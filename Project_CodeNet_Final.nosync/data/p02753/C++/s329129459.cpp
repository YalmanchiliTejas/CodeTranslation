#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repA(i,a,b) for(int i=a;i<=b;i++)
#define repD(i,b,a) for(int i=b;i>=a;i--)
#define fill(a) memset(a,0,sizeof(a))
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    string str;
    set<int>st;
    cin>>str;
    rep(i,0,str.size())
    st.insert(str[i]);
    if(st.size()==1)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}
