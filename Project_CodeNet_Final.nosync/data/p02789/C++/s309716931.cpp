//***___********* ___*****___****___***___*********//
/*  |   \  |   | |   |   |   \  |     |     |   |  **
/*  |   |  |   | |___|   |   _  |__   |___  |___|  **
/*  |   |  |   | |   \   |  | | |         | |   |  **
/*  |___/  |___| |    \  |__| | |___  ____| |   |  **
//*************************************************/
#include<bits/stdc++.h>
#define ff double
#define endl "\n"
#define M 1000000007
#define forever while(1)
#define ll long long
#define pb push_back
#define vi vector<long long>
#define mii map<int,int>
#define pii pair<int,int>
#define set_zero(arr) memset(arr,0,sizeof(arr))
#define test ll t;cin>>t;while(t--)
#include <ext/pb_ds/tree_policy.hpp>
#define REP(i,n) for(int i=0;i<(n);i++)
#include <ext/pb_ds/assoc_container.hpp>
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define buffer cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
bool comp(string a,string b){return a<b;}

int main()
{
    int n,m;
    cin>>n>>m;
    if(n==m)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    



return 0;
}


