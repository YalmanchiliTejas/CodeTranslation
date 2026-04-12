#include <iostream>

int solve(int a, std::string str, int k){
    int m = str[str.length()-a] - '0';
    if(a < k) return 0;
    if(!m) return solve(a-1, str, k);
    switch (k) {
    case 1:
        return m + 9*(a-1); break;
    case 2:
        return (m-1)*(a-1)*9 + (a-1)*(a-2)/2*81 + solve(a-1, str, 1); break;
    case 3:
        return (m-1)*(a-1)*(a-2)/2*81 + (a-1)*(a-2)*(a-3)/6*729 + solve(a-1, str, 2); break;
    }
}

int main(int argc, char *argv[])
{
    std::string s;
    int k;
    std::cin >> s >> k;
    std::cout << solve(s.length(), s, k) << std::endl;
    return 0;
}

