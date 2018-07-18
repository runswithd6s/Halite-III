#include "Constants.hpp"

#include "nlohmann/json.hpp"

/** A JSON key and value corresponding to a game constant. */
#define FIELD_TO_JSON(x) {#x, constants.x}

/** Get a field from JSON. */
#define FIELD_FROM_JSON(x) json.at(#x)

namespace hlt {

/**
 * Encode the constants to JSON.
 * @param[out] json The JSON output.
 * @param constants The constants.
 */
void to_json(nlohmann::json &json, const Constants &constants) {
    json = {FIELD_TO_JSON(MAX_TURNS),
            FIELD_TO_JSON(MAX_PLAYERS),
            FIELD_TO_JSON(DEFAULT_MAP_WIDTH),
            FIELD_TO_JSON(DEFAULT_MAP_HEIGHT),
            FIELD_TO_JSON(MAX_CELL_PRODUCTION),
            FIELD_TO_JSON(MIN_CELL_PRODUCTION),
            FIELD_TO_JSON(MAX_ENERGY),
            FIELD_TO_JSON(NEW_ENTITY_ENERGY_COST),
            FIELD_TO_JSON(NEW_ENTITY_ENERGY),
            FIELD_TO_JSON(BASE_TURN_ENERGY_LOSS),
            FIELD_TO_JSON(INITIAL_ENERGY),
            FIELD_TO_JSON(PERSISTENCE),
            FIELD_TO_JSON(FACTOR_EXP_1),
            FIELD_TO_JSON(FACTOR_EXP_2),
            FIELD_TO_JSON(DROPOFF_COST),
            FIELD_TO_JSON(MOVE_COST_RATIO),
            FIELD_TO_JSON(DROPOFF_PENALTY_RATIO),
            FIELD_TO_JSON(EXTRACT_RATIO)};
}

/**
 * Decode the constants from JSON.
 * @param json The JSON input.
 * @param[out] constants The decoded constants.
 */
void from_json(const nlohmann::json &json, Constants &constants) {
    constants = {FIELD_FROM_JSON(MAX_TURNS),
                 FIELD_FROM_JSON(MAX_PLAYERS),
                 FIELD_FROM_JSON(DEFAULT_MAP_WIDTH),
                 FIELD_FROM_JSON(DEFAULT_MAP_HEIGHT),
                 FIELD_FROM_JSON(MAX_CELL_PRODUCTION),
                 FIELD_FROM_JSON(MIN_CELL_PRODUCTION),
                 FIELD_FROM_JSON(MAX_ENERGY),
                 FIELD_FROM_JSON(NEW_ENTITY_ENERGY_COST),
                 FIELD_FROM_JSON(NEW_ENTITY_ENERGY),
                 FIELD_FROM_JSON(BASE_TURN_ENERGY_LOSS),
                 FIELD_FROM_JSON(INITIAL_ENERGY),
                 FIELD_FROM_JSON(DROPOFF_COST),
                 FIELD_FROM_JSON(MOVE_COST_RATIO),
                 FIELD_FROM_JSON(DROPOFF_PENALTY_RATIO),
                 FIELD_FROM_JSON(EXTRACT_RATIO),
                 FIELD_FROM_JSON(PERSISTENCE),
                 FIELD_FROM_JSON(FACTOR_EXP_1),
                 FIELD_FROM_JSON(FACTOR_EXP_2),};
}

}
