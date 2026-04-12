#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int MOD=1e9+7;
template<typename A,size_t N,typename T>
void Fill(A (&array)[N],const T &val)
{
    std::fill( (T*)array,(T*)(array+N),val );
}
int main(void)
{
    string s;
    cin >> s;
    if(s[0]!=s[1] || s[0]!=s[2] || s[1]!=s[2]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}