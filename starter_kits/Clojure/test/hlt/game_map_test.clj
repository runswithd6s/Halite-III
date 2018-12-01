(ns hlt.game-map-test
  (:require [clojure.test :refer :all]
            [hlt.ship :as ship]
            [hlt.player :as player]
            [hlt.shipyard :as shipyard]
            [hlt.direction :as direction]
            [hlt.game-map :refer :all]))

(deftest test-naive-navigate
  (with-redefs [game-map  (fn [] {:width 32  :height 32})]
  (let [ship {::ship/id 1 ::player/id 0 :position [8 10] :halite 100}
        shipyard {::shipyard/id -1  ::player/id 0 :position [8 16]}]
    (is (= [0 1] (naive-navigate ship shipyard))))))

(deftest test-get-target-direction
  (with-redefs [game-map (fn [] {:width 32 :height 32})]
    ;; one direction -- not shortest
    (is (= (get-target-direction [0 0] [0 32]) [nil direction/south]))
    (is (= (get-target-direction [0 0] [0 1]) [nil direction/south]))
    (is (= (get-target-direction [0 0] [1 0]) [direction/east nil]))
    (is (= (get-target-direction [0 0] [32 0]) [direction/east nil]))
    ;; two directions
    (is (= (get-target-direction [1 1] [0 2]) [direction/west direction/south]))
    (is (= (get-target-direction [1 1] [0 0]) [direction/west direction/north]))
    (is (= (get-target-direction [1 1] [2 2]) [direction/east direction/south]))
    (is (= (get-target-direction [1 1] [2 0]) [direction/east direction/north]))
    ))
