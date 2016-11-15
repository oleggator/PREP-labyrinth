//
// Created by tsv on 09.05.16.
//

#include "Runner.hpp"
#include <vector>
#include <cstdlib>
#include "utils.hpp"
#include <ctime>


Direction Runner::step() {
    BlockType forward;
    //BlockType back;
    BlockType left;
    BlockType right;

    Direction forwardDirection;
    Direction backDirection;
    Direction leftDirection;
    Direction rightDirection;

    switch (currentDirection) {

    case Direction::UP:
        forward = current_status.up;
        //back = current_status.down;
        left = current_status.left;
        right = current_status.right;

        forwardDirection = Direction::UP;
        backDirection = Direction::DOWN;
        leftDirection = Direction::LEFT;
        rightDirection = Direction::RIGHT;

        break;

    case Direction::DOWN:
        forward = current_status.down;
        //back = current_status.up;
        left = current_status.right;
        right = current_status.left;

        forwardDirection = Direction::DOWN;
        backDirection = Direction::UP;
        leftDirection = Direction::RIGHT;
        rightDirection = Direction::LEFT;
        break;

    case Direction::LEFT:
        forward = current_status.left;
        //back = current_status.right;
        left = current_status.down;
        right = current_status.up;

        forwardDirection = Direction::LEFT;
        backDirection = Direction::RIGHT;
        leftDirection = Direction::DOWN;
        rightDirection = Direction::UP;

        break;

    case Direction::RIGHT:
        forward = current_status.right;
        //back = current_status.left;
        left = current_status.up;
        right = current_status.down;

        forwardDirection = Direction::RIGHT;
        backDirection = Direction::LEFT;
        leftDirection = Direction::UP;
        rightDirection = Direction::DOWN;

        break;
    }

    if (left == BlockType::EXIT){
        currentDirection = leftDirection;
    } else if (forward == BlockType::EXIT) {
        currentDirection = forwardDirection;
    } else if (right == BlockType::EXIT) {
        currentDirection = rightDirection;
    } else if (left == BlockType::FREE || left == BlockType::ENTER){
        currentDirection = leftDirection;
    } else if (forward == BlockType::FREE || forward == BlockType::ENTER) {
        currentDirection = forwardDirection;
    } else if (right == BlockType::FREE || right == BlockType::ENTER) {
        currentDirection = rightDirection;
    } else {
        currentDirection = backDirection;
    }

    return currentDirection;
}


