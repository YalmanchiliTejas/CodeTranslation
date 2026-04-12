#include<bits/stdc++.h>
//typedef long long ll;
//#define ull       unsigned long long
#define int       long long
#define F           first
#define S           second
#define endl        "\n"//<<flush
#define eps         1e-6
#define lowbit(x)   (x&(-x))
#define PI          acos(-1.0)
#define inf         0x3f3f3f3f
#define MAXN        0x7fffffff
#define INF         0x3f3f3f3f3f3f3f3f
#define pa          pair<int,int>
#define ferma(a,b)  pow(a,b-2)
#define pb          push_back
#define all(x)      x.begin(),x.end()
#define memset(a,b) memset(a,b,sizeof(a));
#define IOS         ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;
void file()
{
#ifdef ONLINE_JUDGE
#else
    freopen("cin.txt","r",stdin);
    //  freopen("cout.txt","w",stdout);
#endif
}
signed main()
{
    IOS;
    //file();
    string str;
    cin>>str;
    if(str[0]!=str[1]||str[1]!=str[2])
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}
