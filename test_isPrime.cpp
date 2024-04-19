#include <gtest/gtest.h>
#include <sstream>
#include "songuyento.cpp"

// Test isPrime function
TEST(PrimeNumberTest, NegativeNumber) {
    EXPECT_FALSE(isPrime(-1));
}

TEST(PrimeNumberTest, Zero) {
    EXPECT_FALSE(isPrime(0));
}

TEST(PrimeNumberTest, One) {
    EXPECT_FALSE(isPrime(1));
}

TEST(PrimeNumberTest, PrimeNumber) {
    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(11));
    EXPECT_TRUE(isPrime(13));
    EXPECT_TRUE(isPrime(17));
}

TEST(PrimeNumberTest, NonPrimeNumber) {
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(6));
    EXPECT_FALSE(isPrime(8));
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(10));
}

// Test main function
TEST(PrimeNumberTest, MainWithNegativeNumber) {
    std::istringstream input("-1");
    std::ostringstream output;
    
    // Redirect input and output
    std::streambuf* oldInput = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());
    
    // Run main function
    main();
    
    // Restore input and output
    std::cin.rdbuf(oldInput);
    std::cout.rdbuf(oldOutput);
    
    EXPECT_EQ("Nhap 1 so nguyen duong: Vui long nhap lai so nguyen duong.\n", output.str());
}

TEST(PrimeNumberTest, MainWithZero) {
    std::istringstream input("0");
    std::ostringstream output;
    
    // Redirect input and output
    std::streambuf* oldInput = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());
    
    // Run main function
    main();
    
    // Restore input and output
    std::cin.rdbuf(oldInput);
    std::cout.rdbuf(oldOutput);
    
    EXPECT_EQ("Nhap 1 so nguyen duong: Vui long nhap lai so nguyen duong.\n", output.str());
}

TEST(PrimeNumberTest, MainWithPositivePrimeNumber) {
    std::istringstream input("5");
    std::ostringstream output;
    
    // Redirect input and output
    std::streambuf* oldInput = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());
    
    // Run main function
    main();
    
    // Restore input and output
    std::cin.rdbuf(oldInput);
    std::cout.rdbuf(oldOutput);
    
    EXPECT_EQ("Nhap 1 so nguyen duong: 5 la so nguyen to\n", output.str());
}

TEST(PrimeNumberTest, MainWithPositiveNonPrimeNumber) {
    std::istringstream input("6");
    std::ostringstream output;
    
    // Redirect input and output
    std::streambuf* oldInput = std::cin.rdbuf(input.rdbuf());
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());
    
    // Run main function
    main();
    
    // Restore input and output
    std::cin.rdbuf(oldInput);
    std::cout.rdbuf(oldOutput);
    
    EXPECT_EQ("Nhap 1 so nguyen duong: 6 khong phai la so nguyen to.\n", output.str());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
