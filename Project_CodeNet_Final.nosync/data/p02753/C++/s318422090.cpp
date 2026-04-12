#include<bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 +7;
//constexpr int mod2 = 998244353;
constexpr int MAXNe5 = 1e5 +7;
constexpr int MAXNe6 = 1e6 + 7;
#pragma region 
inline long long read()
{
	char c = getchar();long long flag = 1, ans = 0;
	while(c < '0' || c > '9'){if(c == '-')flag = -1; c = getchar();}
	while(c >= '0' && c <= '9'){ans = ans * 10 + c - '0'; c = getchar();}
	return (ans * flag);
}
#pragma endregion
// C'est la vie
int main() {
	string s;
    cin >> s;
    if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A' ||s[0] == 'B' && s[1] == 'B' && s[2] == 'B'  ) cout << "No";
    else cout << "Yes";
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
}