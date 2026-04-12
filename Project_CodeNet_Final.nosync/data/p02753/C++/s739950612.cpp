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
#include <ext/pb_ds/tree_policy.hpp>
#define forn(i,n) for(int i=0;i<(n);i++)
#include <ext/pb_ds/assoc_container.hpp>
#define fori(i,a,b) for(int i=(a);i<=(b);i++)
#define TEST_CASE   int t;cin>>t;while(t--)
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define buffer cin.ignore(numeric_limits<streamsize>::max(),'\n');
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
bool check(int n){
    int cnt = 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}

vi tre[100000];

bool ans = true;
bool vis[100000] = { false };
void dfs(int s){
    vis[s]=true;
    if(tre[s].size()>1){
        int cnt = 0;
        for(int i=0;i<tre[s].size();i++){
            int child = tre[s][i];
            if(tre[child].size()==1){
                cnt++;
            }
        }
        if(cnt<3){
            ans=false;
        }
    }
    for(int i=0;i<tre[s].size();i++){
        if(vis[tre[s][i]]==false)
            dfs(tre[s][i]);
    }
}
void solve(){
 string str;
 cin>>str;
 if(str == "AAA"||str =="BBB")
    cout<<"No"<<endl;
 else
    cout<<"Yes"<<endl;
}


int main(){
   //TEST_CASE
   solve();
return 0;
}

