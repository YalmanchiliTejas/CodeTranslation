#include <bits/stdc++.h>
#define ll  long long

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, "\e[31;1m"); fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\e[0m")
#else
    #define eprintf(...) 42
#endif

std::string solve(char C)
{
    if ('a' == C || 'i' == C || 'u' == C || 'e' == C || 'o' == C)
    {
        return "vowel";
    }
    return "consonant";
}

int main(void)
{
    char C;
    std::cin >> C;
    std::cout << solve(C) << std::endl;
    return 0;
}