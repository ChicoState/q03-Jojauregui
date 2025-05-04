/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test {
protected:
    GuesserTest() {} // constructor runs before each test
    virtual ~GuesserTest() {} // destructor cleans up after tests
    virtual void SetUp() {} // sets up before each test (after constructor)
    virtual void TearDown() {} // clean up after each test (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
    Guesser object("Secret");
    ASSERT_EQ(1 + 1, 2);
}

TEST(GuesserTest, Match_CorrectGuess) {
    Guesser object("pass");
    ASSERT_TRUE(object.match("pass"));
}

TEST(GuesserTest, Match_WrongGuess_LocksIfFar) {
    Guesser object("pass");
    ASSERT_FALSE(object.match("xxxx"));
    ASSERT_FALSE(object.match("pass"));
}

TEST(GuesserTest, Match_RemainingDecreases) {
    Guesser object("code");
    object.match("coda");
    ASSERT_EQ(object.remaining(), 2);
}

TEST(GuesserTest, Match_ThreeFailsThenLocked) {
    Guesser object("hint");
    object.match("hant");
    object.match("hunt");
    object.match("hent");
    ASSERT_EQ(object.remaining(), 0);
    ASSERT_FALSE(object.match("hint"));
}

TEST(GuesserTest, CaseSensitivity) {
    Guesser object("Word");
    ASSERT_FALSE(object.match("word"));
    ASSERT_TRUE(object.match("Word"));
}
