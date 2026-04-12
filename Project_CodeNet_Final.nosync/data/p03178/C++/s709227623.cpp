#include <bits/stdc++.h>
using namespace std;
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;
typedef unsigned long long int ull;
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a>b)?b:a)
#define max3(a,b,c) ((a>b)?(a>c)?a:c:(b>c)?b:c)
#define min3(a,b,c) ((a<b)?(a<c)?a:c:(b<c)?b:c)
#define REP(i,a,n) for(ll i=a;i<n;i++)
#define pb push_back
#define mp make_pair

int arr[100000];
ll dp[100000][100][2];
string a;
int d;

ll ds(string x){
    int res=0;
    for(int i=0 ; i<x.length() ; i++){
        res+=x[i]-'0';
    }
    return res;
}

int myMod(int q){
    if(q<0){
        return (d-(abs(q)%d))%d;
    }else{
        return q%d;
    }
}

ll gs(int ind,int n,int sum,int flag){
    //cout << ind << " " << sum << endl;
    if(ind==n){
        return (sum==0 ? 1:0);
    }
    if(dp[ind][sum][flag]!=-1){
        return dp[ind][sum][flag]%1000000007;
    }
    int limit=9;
    if(!flag){
        limit=arr[ind];
    }
    ll res=0;
    for(int i=0 ; i<=limit ; i++){
        if(flag || i<limit){
            res+=gs(ind+1,n,myMod(sum-arr[ind]+i),1);
        }else{
            res+=gs(ind+1,n,myMod(sum-arr[ind]+i),0);
        }
        res%=1000000007;
    }
    return dp[ind][sum][flag]=res%1000000007;
}

int main(){
	fast;
	int test=1;
	//cin >> test;
	while(test--){
	    cin >> a >> d;
	    memset(dp,-1,sizeof dp);
	    for(int i=0 ; i<a.length(); i++){
	        arr[i]=a[i]-'0';
	    }
	    ll left=gs(0,a.size(),ds(a),0);
	    left--;
	    if(left<0){
	        cout << left+1000000007 << endl;
	    }else{
	        cout << left << endl;
	    }
	}
	return 0;
}