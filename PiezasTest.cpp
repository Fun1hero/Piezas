/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// Sanity Check

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}


// Constructor test

TEST(PiezasTest, blank_board)
{
  Piezas board;
  for(int i=0; i < BOARD_ROWS; i++)
  {
    for(int j=0; j < BOARD_COLS; j++)
    {
      ASSERT_EQ(board.pieceAt(i,j), Blank);
    }
  }
}


// Drop piece tests

TEST(PiezasTest, drop_x)
{
  Piezas board;
  Piece piece;
  piece = board.dropPiece(0);
  ASSERT_EQ(piece, X);
}

TEST(PiezasTest, drop_o)
{
  Piezas board;
  Piece piece;
  piece = board.dropPiece(0);
  piece = board.dropPiece(0);
  ASSERT_EQ(piece, O);
}

TEST(PiezasTest, drop_full)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);

  Piece piece;
  piece = board.dropPiece(0);
  ASSERT_EQ(piece, X);
}

TEST(PiezasTest, drop_extra_piece)
{
  Piezas board;
  board.dropPiece(0);
  board.dropPiece(0);
  board.dropPiece(0);

  Piece piece;
  piece = board.dropPiece(0);
  ASSERT_EQ(piece, Blank);
}

TEST(PiezasTest, drop_invalid_position)
{
  Piezas board;
  Piece piece;
  piece = board.dropPiece(10);
  ASSERT_EQ(piece, Invalid);
}

TEST(PiezasTest, drop_invalid_first_turn)
{
  Piezas board;
  board.dropPiece(-1);

  Piece piece;
  piece = board.dropPiece(0);
  ASSERT_EQ(piece, O);
}