#include <iostream>

using namespace std;

int main()
{
    constexpr auto kMealPrice = 800;
    constexpr auto kPayback = 200;
    constexpr auto kPaybackMeals = 15;

    int meals;
    cin >> meals;

    auto res = meals * kMealPrice - (meals / kPaybackMeals) * kPayback;
    cout << res << "\n";

    return 0;
}
