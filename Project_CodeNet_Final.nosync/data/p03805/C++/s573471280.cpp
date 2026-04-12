#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int v[8][8];
vector<string> arr;

void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        arr.pb(a);
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l+1, r);

            //backtrack
            swap(a[l], a[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a][b]=1;
        v[b][a]=1;
    }
    string str="";
    for(int i=2;i<=n;i++){
        char c='0'+i;
        str+=c;
    }
    permute(str,0,n-2);
    ll ans=0;
    for(int i=0;i<arr.size();i++){
        string s="1"+arr[i];
        int count=1;
        for(int i=1;i<=n-1;i++){
            if(v[s[i]-'0'][s[i-1]-'0']==0){
                count=0;
                break;
            }
        }
        if(count==1)
            ans+=1;
    }
    cout<<ans<<endl;
    return 0;
}
