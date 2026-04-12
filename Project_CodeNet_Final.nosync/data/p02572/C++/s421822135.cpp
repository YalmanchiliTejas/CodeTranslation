// -- Nitin
#include <bits/stdc++.h>
#define pb push_back
#define mkp make_pair
#define llu unsigned long long int
#define ll long long
#define ld long double
#define foi(a,n) for(int i = a; i < (int)n; i++)
#define foj(a,n) for(int j = a; j < (int)n; j++)
#define foin(a,n) for(int i = n; i >= a; i--)
#define fojn(a,n) for(int j = n; j >= a; j--)
#define bug(x) cerr << #x << " is " << x << endl;
#define isp2(x) x&&(!(x&(x-1)))
#define ln '\n'
#define ee 1000000007
#define eem 998244353
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cases int tests; cin >> tests; while(tests--)

using namespace std;

ll fast(ll n,ll k){
    ll res = 1;
    n = n;
    while(k > 0){
        if ((k&1) == 1)
            res = (res * n);
        k = k>>1;
        n = (n * n);
    }
    return res;
}
 
//~ ll strsum(string s){
    //~ ll sm = 0, r = s.size();
    //~ foi(0,r)    sm += int(s[i]-'a');
    //~ return sm;
//~ }
 
//~ set <ll, greater <ll> > ss; //Prime Factors
//~ void pF(ll n)  {    
    //~ while (n % 2 == 0)  {  
        //~ ss.insert(2);  
        //~ n = n/2;  
    //~ }  
    //~ for (int i = 3; i <= sqrt(n); i = i + 2)  {   
        //~ while (n % i == 0)  {  
            //~ ss.insert(i); 
            //~ n = n/i;  
        //~ }  
    //~ }    
    //~ if (n > 2)  ss.insert(n);  
//~ }

//~ ll pre[1001][1001];

//~ ll go(ll n, ll k){
	//~ if(n==1) return 1;
	//~ else {
		//~ pre[n][k] = (go(n - 1, k) + k - 1) % n + 1;
		//~ return pre[n][k];
	//~ }
//~ }

//~ int dp[1002][1002];
//~ bool pal(string s){
	//~ for(int i = 0, j = s.size() - 1; i < s.size(); i++, j--){
		//~ if(s[i] != s[j]) return 0;
	//~ }
	//~ return 1;
//~ }

//~ void solve(){
	//~ int n;
	//~ cin >> n;		
//~ }


void go(){
	int n;
	cin >> n;
	ll a[n], sum = 0;
	foi(0, n) {
		cin >> a[i];
		sum = (sum%ee + a[i]%ee)%ee;
	}
	ll val = 0, ans = 0;
	for(int i = 0; i < n-1; i++){
		 val = (val%ee + a[i]%ee)%ee;
		 ll x = sum - val;
		 if(x < 0) x = (x+ee);
		 ans = (ans%ee + ((a[i]%ee)*x)%ee)%ee;
	}
	cout << ans % ee;
	
}

int main(){
    fio;
	//~ ll q, n, x, m , y;
	//~ string t;
	//~ for(int i = 1; i <= 1000; i++){
		//~ pre[1][i]=1;
		//~ go(1000,i);
	//~ }
	ll n, m, k;
    //~ cases
    {	
		go();
		cout << "\n";
	}
}
       
        
