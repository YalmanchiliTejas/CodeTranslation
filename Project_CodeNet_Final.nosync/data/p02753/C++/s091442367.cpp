#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
template <typename T>
inline T  read()
{
    char c=getchar();
    T x=0,f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
template <typename T>
inline void write(T x) 
{
    if(x < 0) x = (~x) + 1, putchar('-');
    if(x / 10) write(x / 10);
    putchar(x % 10 | 48);
}
const int INF = 0x3f3f3f3f;
int main()
{
    string str;
    cin>>str;
    if(str == "AAA" || str == "BBB") cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}