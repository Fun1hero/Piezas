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


// Piece at test

TEST(PiezasTest, check_blank)
{
  Piezas board;
  Piece piece;
  piece = board.pieceAt(0,0);
  ASSERT_EQ(piece, Blank);
}

TEST(PiezasTest, expect_x_at_pos)
{
  Piezas board;
  Piece piece;
  board.dropPiece(0);
  piece = board.pieceAt(0,0);
  ASSERT_EQ(piece, X);
}

TEST(PiezasTest, expect_o_at_pos)
{
  Piezas board;
  Piece piece;
  board.dropPiece(0);
  board.dropPiece(0);
  piece = board.pieceAt(1,0);
  ASSERT_EQ(piece, O);
}

TEST(PiezasTest, out_of_range_arguments)
{
  Piezas board;
  Piece piece;
  piece = board.pieceAt(7,0);
  ASSERT_EQ(piece, Invalid);
}


// Reset board test

TEST(PiezasTest, reset_simple)
{
  Piezas board;
  for(unsigned int i=0; i < BOARD_ROWS; i++)
    for(unsigned int j=0; j < BOARD_COLS; j++)
		board.dropPiece(i);

  board.reset();
  for(unsigned int i=0; i < BOARD_ROWS; i++)
    for(unsigned int j=0; j < BOARD_COLS; j++)
      ASSERT_EQ(board.pieceAt(i,j), Blank);
}


// Game state