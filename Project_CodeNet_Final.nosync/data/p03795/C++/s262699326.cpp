#include <iostream>

int main()
{
    unsigned int n;  // The number of meals ordered by customer.
    std::cin >> n;

    unsigned int PricePerMeal  { 800 };
    unsigned int CustomerPaid  { n * PricePerMeal };
    unsigned int PaidBackPer15 { 200 };
    unsigned int PaidBack      { n / 15 * PaidBackPer15 };
    unsigned int RealCost      { CustomerPaid - PaidBack };     

    std::cout << RealCost << std::endl;

    return 0;
}