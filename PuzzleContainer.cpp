//Muhammad Ali Waris 22001037
#pragma once
#include <iostream>
using namespace std;
#include "PuzzleContainer.h"

void shapeConverter(char shape, int& left, int& right, int& up, int& down) {
    down = shape % 4;
    up = (shape / 4) % 4;
    right = (shape / 16) % 4;
    left = shape / 64;
}

PuzzleContainer::PuzzleContainer(int h, int w) {
    height = h;
    width = w;
    rowLists = new PuzzleRow[h];
    for (int i = 0; i < h; i++) {
        rowLists[i] = PuzzleRow(w, i);
    }

}

PuzzleRow::PuzzleRow() {
}

void PuzzleRow::setMaxSize(int size) {
    this->maxSize = size;
}

void PuzzleRow::setRowIndex(int rowIndex) {
    this->rowindex = rowIndex;
}



bool PuzzleContainer::checkLeft(int row, int col, unsigned char shape2) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row;
    coluIndex = col;
    unsigned char tempShape = NULL;
    int left, right, up, down;
    int templeft, tempright, tempup, tempdown;

    for (int i = 0; i < height; i++) {
        if (i == rowIndex) {
            this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
            while (this->rowLists[i].publicTemp != NULL)
            {
                if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                    if (this->rowLists[i].publicTemp->shape == 0xFF) {
                        // Other Coniditionssssssss ........
                        return true;
                    }
                    else {
                        tempShape = this->rowLists[i].publicTemp->shape;
                    }
                }


                this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
            }
        }
    }

    shapeConverter(shape2, left, right, up, down);
    shapeConverter(tempShape, templeft, tempright, tempup, tempdown);


    if (col == 0) {
        if (left == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (col < 0) {
        if (left == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if ((tempright == 1 && left == 0) || (tempright == 0 && left == 1)) {
        return true;
    }

    return false;

}

bool PuzzleContainer::checkRight(int row, int col, unsigned char shape2) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row;
    coluIndex = col;
    unsigned char tempShape = NULL;
    int left, right, up, down;
    int templeft, tempright, tempup, tempdown;

    for (int i = 0; i < height; i++) {
        if (i == rowIndex) {
            this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
            while (this->rowLists[i].publicTemp != NULL)
            {
                if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                    if (this->rowLists[i].publicTemp->shape == 0xFF) {
                        // Other Coniditionssssssss ........
                        return true;
                    }
                    else {
                        tempShape = this->rowLists[i].publicTemp->shape;
                    }
                }


                this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
            }
        }
    }

    shapeConverter(shape2, left, right, up, down);
    shapeConverter(tempShape, templeft, tempright, tempup, tempdown);

    if ((col - 1) == (width - 1)) {
        if (right == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (col < 0) {
        if (right == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if ((templeft == 1 && right == 0) || (templeft == 0 || right == 1)) {
        return true;
    }

    return false;

}

bool PuzzleContainer::checkUp(int row, int col, unsigned char shape2) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row;
    coluIndex = col;
    unsigned char tempShape = NULL;
    int left, right, up, down;
    int templeft, tempright, tempup, tempdown;

    for (int i = 0; i < height; i++) {
        if (i == rowIndex) {
            this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
            while (this->rowLists[i].publicTemp != NULL)
            {
                if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                    if (this->rowLists[i].publicTemp->shape == 0xFF) {
                        // Other Coniditionssssssss ........

                        return true;
                    }
                    else {
                        tempShape = this->rowLists[i].publicTemp->shape;
                    }
                }


                this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
            }
        }
    }

    shapeConverter(shape2, left, right, up, down);
    shapeConverter(tempShape, templeft, tempright, tempup, tempdown);

    if ((row + 1) == 0) {
        if (up == 2) {
            return true;
        }

    }
    else if (row < 0) {
        if (up == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if ((tempdown == 0 && up == 2) || (tempdown == 2 && up == 0)) {
        return false;
    }
    else if ((tempdown == 1 && up == 0) || (tempdown == 0 || up == 1)) {
        return true;
    }
    else {
        return false;

    }

    return false;

}

bool PuzzleContainer::checkDown(int row, int col, unsigned char shape2) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row;
    coluIndex = col;
    unsigned char tempShape = NULL;
    int left, right, up, down;
    int templeft, tempright, tempup, tempdown;

    for (int i = 0; i < height; i++) {
        if (i == rowIndex) {
            this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
            while (this->rowLists[i].publicTemp != NULL)
            {
                if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                    if (this->rowLists[i].publicTemp->shape == 0xFF) {
                        // Other Coniditionssssssss ........

                        return true;
                    }
                    else {
                        tempShape = this->rowLists[i].publicTemp->shape;
                    }
                }


                this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
            }
        }
    }

    shapeConverter(shape2, left, right, up, down);
    shapeConverter(tempShape, templeft, tempright, tempup, tempdown);


    if (row == (height - 1)) {
        if (down == 2) {
            return true;
        }
    }
    else if (row < 0) {
        if (down == 2) {
            return true;
        }
        else {
            return false;
        }
    }
    else if ((tempup == 1 && down == 0) || (tempup == 0 || down == 1)) {
        return true;
    }

    return false;

}




bool PuzzleContainer::checkAllPositions(int row, int col, unsigned char shape2) {
    int height, width, centreRowIndex, centreColuIndex;
    width = this->width;
    centreRowIndex = row;
    centreColuIndex = col;
    //check for centre positon and place it
    if (!checkLeft(centreRowIndex, centreColuIndex - 1, shape2)) {
        return false;
    }
    else if (!checkRight(centreRowIndex, centreColuIndex + 1, shape2)) {

        return false;
    }
    else if (!checkUp(centreRowIndex - 1, centreColuIndex, shape2)) {

        return false;
    }
    else if (!checkDown(centreRowIndex + 1, centreColuIndex, shape2)) {

        return false;
    }

    return true;
}


void PuzzleContainer::displayContainer() {
    cout << " ";
    for (int i = 0; i < this->width; i++) {
        cout << " " << i + 1;
    }
    cout << endl;
    for (int i = 0; i < this->height; i++) {
        cout << i + 1;
        this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
        while (this->rowLists[i].publicTemp != NULL)
        {

            if (this->rowLists[i].publicTemp->shape != 0xFF) {
                cout << " X";
            }
            else {
                cout << " O";
            }

            this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
        }
        cout << endl;
    }
}

void PuzzleContainer::showColumn(int col) {
    int height, width, coluIndex;
    height = this->height;
    width = this->width;
    coluIndex = col - 1;
    unsigned char tempShape = NULL;

    if (col < 1 || col > width) {
        cout << col << " Out of Bounds " << endl;
    }
    else {
        cout << "Showing Column " << col << endl;
        for (int i = 0; i < height; i++) {

            this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
            while (this->rowLists[i].publicTemp != NULL)
            {
                if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                    if (this->rowLists[i].publicTemp->shape == 0xFF) {
                        cout << "O" << endl;
                    }
                    else {
                        cout << "X" << endl;
                    }
                }


                this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
            }

        }
    }

}


void PuzzleContainer::findPiece(unsigned char shape2) {
    int height, width;
    height = this->height;
    width = this->width;
    bool found = false;


    for (int i = 0; i < height; i++) {

        this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
        while (this->rowLists[i].publicTemp != NULL)
        {

            if (this->rowLists[i].publicTemp->shape == shape2) {
                // Other Coniditionssssssss ........

                cout << "Piece found at " << this->rowLists[i].publicTemp->rowindex + 1 << "x" << this->rowLists[i].publicTemp->colindex + 1 << endl;
                found = true;
            }




            this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
        }

    }

    if (!found) {
        cout << "Piece Not Found " << endl;
        cout << " With the shape : " << endl;

        int left, right, up, down;
        shapeConverter(shape2, left, right, up, down);
        if (left == 0) {
            cout << "Left Side : HOLE" << endl;
        }
        else if (left == 1) {
            cout << "Left Side : KNOB" << endl;
        }
        else if (left == 2) {
            cout << "Left Side : BORDER" << endl;
        }

        if (right == 0) {
            cout << "Right Side : HOLE" << endl;
        }
        else if (right == 1) {
            cout << "Right Side : KNOB" << endl;
        }
        else if (right == 2) {
            cout << "Right Side : BORDER" << endl;
        }

        if (up == 0) {
            cout << "Up Side : HOLE" << endl;
        }
        else if (up == 1) {
            cout << "Up Side : KNOB" << endl;
        }
        else if (up == 2) {
            cout << "Up Side : BORDER" << endl;
        }

        if (down == 0) {
            cout << "Down Side : HOLE" << endl;
        }
        else if (down == 1) {
            cout << "Down Side : KNOB" << endl;
        }
        else if (down == 2) {
            cout << "Down Side : BORDER" << endl;
        }
    }
    else {
        int left, right, up, down;
        cout << " With : " << endl;
        shapeConverter(shape2, left, right, up, down);
        if (left == 0) {
            cout << "Left Side : HOLE" << endl;
        }
        else if (left == 1) {
            cout << "Left Side : KNOB" << endl;
        }
        else if (left == 2) {
            cout << "Left Side : BORDER" << endl;
        }

        if (right == 0) {
            cout << "Right Side : HOLE" << endl;
        }
        else if (right == 1) {
            cout << "Right Side : KNOB" << endl;
        }
        else if (right == 2) {
            cout << "Right Side : BORDER" << endl;
        }

        if (up == 0) {
            cout << "Up Side : HOLE" << endl;
        }
        else if (up == 1) {
            cout << "Up Side : KNOB" << endl;
        }
        else if (up == 2) {
            cout << "Up Side : BORDER" << endl;
        }

        if (down == 0) {
            cout << "Down Side : HOLE" << endl;
        }
        else if (down == 1) {
            cout << "Down Side : KNOB" << endl;
        }
        else if (down == 2) {
            cout << "Down Side : BORDER" << endl;
        }
    }



}

void PuzzleContainer::showRow(int row) {
    int height, width, rowIndex;
    height = this->height;
    width = this->width;
    rowIndex = row - 1;
    unsigned char tempShape = NULL;
    int left, right, up, down;
    int templeft, tempright, tempup, tempdown;

    if (row < 1 || row > height) {
        cout << row << " Out of Bounds " << endl;
    }
    else {
        cout << "Showing Row " << row << endl;

        for (int i = 0; i < height; i++) {
            if (i == rowIndex) {
                this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
                while (this->rowLists[i].publicTemp != NULL)
                {

                    if (this->rowLists[i].publicTemp->shape == 0xFF) {
                        cout << " O";
                    }
                    else {
                        cout << " X";
                    }



                    this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
                }
            }
        }
    }
}

bool PuzzleContainer::addPiece(int row, int col, unsigned char shape2) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row - 1;
    coluIndex = col - 1;

    if (row < 1 || row > height || col < 1 || col > width) {
        cout << row << "x" << col << " Out of Bounds " << endl;
    }
    else {
        if (checkAllPositions(rowIndex, coluIndex, shape2)) {
            for (int i = 0; i < height; i++) {
                if (i == rowIndex) {
                    this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
                    while (this->rowLists[i].publicTemp != NULL)
                    {
                        if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                            if (this->rowLists[i].publicTemp->shape == 0xFF) {
                                // Other Coniditionssssssss ........

                                this->rowLists[i].publicTemp->shape = shape2;
                                cout << "A Piece is added to " << row << "x" << col << endl;
                                return true;
                            }
                            else {
                                cout << row << "x" << col << " is occupied " << endl;
                            }
                        }


                        this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
                    }
                }
            }
        }
        cout << "Shape doesnt fit into " << row << "x" << col << ", it cannot be added " << endl;
    }
    return false;
}

bool PuzzleContainer::removePiece(int row, int col) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row - 1;
    coluIndex = col - 1;

    if (row < 1 || row > height || col < 1 || col > width) {
        cout << row << "x" << col << " Out of Bounds " << endl;
    }
    else {

        for (int i = 0; i < height; i++) {
            if (i == rowIndex) {
                this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
                while (this->rowLists[i].publicTemp != NULL)
                {
                    if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                        if (this->rowLists[i].publicTemp->shape == 0xFF) {
                            // Other Coniditionssssssss ........


                            cout << "No Piece At  " << row << "x" << col << " it cannot be removed " << endl;
                            return false;
                        }
                        else {
                            this->rowLists[i].publicTemp->shape = 0xFF;
                            cout << row << "x" << col << " is REMOVED " << endl;
                            return true;

                        }
                    }


                    this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
                }
            }
        }
    }
    return false;
}

void PuzzleContainer::showPiece(int row, int col) {
    int height, width, rowIndex, coluIndex;
    height = this->height;
    width = this->width;
    rowIndex = row - 1;
    coluIndex = col - 1;
    unsigned char tempShape = 0xFF;
    int left, right, up, down;

    if (row < 1 || row > height || col < 1 || col > width) {
        cout << row << "x" << col << " Out of Bounds " << endl;
    }
    else {

        for (int i = 0; i < height; i++) {
            if (i == rowIndex) {
                this->rowLists[i].publicTemp = this->rowLists[i].publicHead;
                while (this->rowLists[i].publicTemp != NULL)
                {
                    if (this->rowLists[i].publicTemp->colindex == coluIndex) {
                        if (this->rowLists[i].publicTemp->shape == 0xFF) {
                            // Other Coniditionssssssss ........

                            cout << "There is no piece on " << row << "x" << col << " it cannot be shown " << endl;

                        }
                        else {
                            tempShape = this->rowLists[i].publicTemp->shape;
                        }
                    }


                    this->rowLists[i].publicTemp = this->rowLists[i].publicTemp->next;
                }
            }
        }
        if (tempShape == 0xFF) {

        }
        else {
            cout << "Piece at " << row << "x" << col << " has the following " << endl;
            shapeConverter(tempShape, left, right, up, down);
            if (left == 0) {
                cout << "Left Side : HOLE" << endl;
            }
            else if (left == 1) {
                cout << "Left Side : KNOB" << endl;
            }
            else if (left == 2) {
                cout << "Left Side : BORDER" << endl;
            }

            if (right == 0) {
                cout << "Right Side : HOLE" << endl;
            }
            else if (right == 1) {
                cout << "Right Side : KNOB" << endl;
            }
            else if (right == 2) {
                cout << "Right Side : BORDER" << endl;
            }

            if (up == 0) {
                cout << "Up Side : HOLE" << endl;
            }
            else if (up == 1) {
                cout << "Up Side : KNOB" << endl;
            }
            else if (up == 2) {
                cout << "Up Side : BORDER" << endl;
            }

            if (down == 0) {
                cout << "Down Side : HOLE" << endl;
            }
            else if (down == 1) {
                cout << "Down Side : KNOB" << endl;
            }
            else if (down == 2) {
                cout << "Down Side : BORDER" << endl;
            }

        }


    }

}

PuzzleRow::PuzzleRow(int size, int rowindex2) {
    this->rowindex = rowindex2;
    this->maxSize = size;


    for (int i = 0; i < size; i++)
    {
        this->currentNode = new PuzzlePiece; 
        this->currentNode->colindex = i;
        this->currentNode->rowindex = rowindex;
        this->currentNode->shape = 0xFF;

        if (i == 0)
        {
            this->head = this->temp = this->currentNode;
        }
        else
        {
            this->temp->next = this->currentNode;
            this->temp = this->currentNode;
        }
    }

    this->temp->next = NULL;
    this->temp = this->head;
    this->publicHead = this->head;

}
