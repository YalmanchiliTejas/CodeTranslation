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

int arr[51][26];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            char c=s[j];
            int k=c-'a';
            arr[i][k]+=1;
        }
    }
    for(int j=0;j<26;j++){
        int count=51;
        for(int i=0;i<n;i++){
            if(arr[i][j]<count)
                count=arr[i][j];
        }
        for(int i=0;i<count;i++){
            char c='a'+j;
            cout<<c;
        }
    }
    cout<<endl;
    return 0;
}
