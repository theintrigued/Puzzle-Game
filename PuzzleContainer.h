//Muhammad Ali Waris 22001037

#pragma once
#include <iostream>
using namespace std;





class PuzzleRow {
private:
	struct PuzzlePiece {
		unsigned char shape;
		int rowindex;
		int colindex;
		PuzzlePiece* next;
	};

	PuzzlePiece* head, * currentNode, * temp;
	PuzzleRow* next;
	int rowindex;
	int maxSize; //equals to puzzleContainer width


public:
	PuzzlePiece* publicHead;
	PuzzlePiece* publicTemp;
	PuzzleRow(int size, int rowindex);
	PuzzleRow();
	void setMaxSize(int size);
	void setRowIndex(int rowIndex);


}; // END PUZZLE ROW CLASS


class PuzzleContainer {
private:
	PuzzleRow* rowLists;
	int height;
	int width;
public:
	PuzzleRow* publicRowLists;

	PuzzleContainer(int h, int w);
	void displayContainer();
	bool addPiece(int row, int col, unsigned char shape);
	bool checkAllPositions(int row, int col, unsigned char shape);
	bool checkLeft(int row, int col, unsigned char shape);
	bool checkRight(int row, int col, unsigned char shape);
	bool checkUp(int row, int col, unsigned char shape);
	bool checkDown(int row, int col, unsigned char shape);
	bool removePiece(int row, int col);
	void showPiece(int row, int col);
	void showColumn(int col);
	void showRow(int row);
	void findPiece(unsigned char shape);









};
