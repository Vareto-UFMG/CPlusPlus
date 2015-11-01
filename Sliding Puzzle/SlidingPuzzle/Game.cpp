//
//  Game.cpp
//  SlidingPuzzle
//
//  Created by Rafael Vareto on 10/31/15.
//  Copyright © 2015 Universidade Federal de Minas Gerais. All rights reserved.
//

#include "Game.hpp"

/*
 * Public Methods
 */

Game::Game(string _fileName) {
    this->readFile(_fileName);

    this->current = new State(this->size, this->rawInput);
    this->goal = new State(this->size);
    this->start = new State(this->size, this->rawInput);
    
    this->current->swap(DOWN);
}


Game::Game(int _size, State &_state) {
    this->rawInput.clear();
    this->size = _size;
    
    this->current = new State(_state);
    this->goal = new State(this->size);
    this->start = new State(_state);
}


Game::~Game() {
    delete this->current;
    delete this->goal;
    delete this->start;
}


State Game::getCurrent() {
    State temporary = *this->current;
    return temporary;
}


State Game::getGoal() {
    return *this->goal;
}


State Game::getStart() {
    return *this->start;
}


bool Game::readFile(string _fileName) {
    string tile;
    ifstream infile(_fileName, ifstream::in);
    
    if (infile.is_open()) {
        if (infile.good()) {
            infile >> this->size;
        }
        while (infile.good()) {
            infile >> tile;
            this->rawInput.push_back(tile);
        }
        return true;
    } else {
        cerr << "SlidingPuzzle could not read input file.\n";
        return false;
    }
}


bool Game::solve() {
    return false;
}

/*
 * Private Methods
 */

vector<int> Game::getMoves(const int x, const int y) {
    vector<int> moves;
    vector<string> movement;
    
    if ((x > 0) and (x < this->size)) {
        moves.push_back(UP);
    }
    if ((y >= 0) and (y < this->size - 1)) {
        moves.push_back(RIGHT);
    }
    if ((x >= 0) and (x < this->size - 1)) {
        moves.push_back(DOWN);
    }
    if ((y > 0) and (y < this->size)) {
        moves.push_back(LEFT);
    }
    
    return moves;
}