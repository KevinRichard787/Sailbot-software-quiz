#include "stdbool.h"
#include "standard_calc.h"
#include <math.h>
#include <algorithm>  
/**
 * @brief Bounds the provided angle between [-180, 180) degrees.
 *
 * e.g.)
 *      bound_to_180(135) = 135.0
 *      bound_to_180(200) = -160.0
 *
 * @param angle: The input angle in degrees.
 *
 * @return float: The bounded angle in degrees.
 */
float bound_to_180(float angle) {
    //assumptions: Since there are no rules set for the angles, this assumes that the angle
    //given can be below -360 or above 360
    if (angle >= -180 && angle < 180){
        return angle;
    }
    //remainder in floating point form. Puts angle in the [-360,360) space
    angle = fmodf(angle, 360.0f);

    //if it is in the  [-360,-180) range, add 360 to put it in the [-180, 180) range
    if (angle < -180.0f)  {
        angle += 360.0f;

    //if it is in the  [180, 360) range, add 360 to put it in the [-180, 180) range
    }else if (angle >= 180.0f){
        angle -= 360.0f;  
    }
    return angle;
   
}

static float normalize_angle(float angle){
    angle =  fmodf(angle, 360.0f);
    if (angle <0) angle+=360;
    return angle;
}
/**
 * @brief Determines whether an angle is between two other angles
 *
 *  e.g.)
 *      is_angle_between(0, 45, 90) = true
 *      is_angle_between(45, 90, 270) = false
 * 
 * @param first_angle:  The first bounding angle in degrees.
 * @param middle_angle: The angle in question in degrees.
 * @param second_angle: The second bounding angle in degrees.
 * @return bool: TRUE when `middle_angle` is not in the reflex angle of `first_angle` and `second_angle`, FALSE otherwise
 */
bool is_angle_between(float first_angle, float middle_angle, float second_angle) {
    //assumptions: Since there are no rules set for the angles, this assumes that the angles
    //given can be below -360 or above 360
    // In this case, it is assumed that between is inclusive
  
    //first, bound the angles to the [0,360) range
    first_angle = normalize_angle(first_angle);
    second_angle = normalize_angle(second_angle);
    middle_angle = normalize_angle(middle_angle);
    float diff = second_angle - first_angle;
    if (diff < 0.0f) diff += 360.0f;   
    //if diff >180, then first angle is the larger angle
    if (diff >= 180.0f) {              
        std::swap(first_angle,second_angle);
    }

    if (first_angle <= second_angle) return middle_angle >= first_angle && middle_angle <= second_angle;
    else return middle_angle >= first_angle || middle_angle <= second_angle;

    
}