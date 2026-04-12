/*
Author Shivam
*/
#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define m_p			make_pair
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i =a, i>=b;i--)
#define sz(x)       (int)x.size()
#define F			first
#define S			second
#define debug(x)	for(int i=0;i<x;i++) cout<<"##########"<<endl
#define M			1000000007 
#define int			long long int
#define lMax		LLONG_MAX
#define pii 		pair<int ,int >
#define	all(a)		a.begin(), a.end()
#define vi 			vector<int> 
#define vii 		vector<pii> 
#define ve          vector
#define endl		"\n"
#define double 		long double
#define couts		cout<<setprecision(12)<<fixed					
// queue<int> , prefix_sum(a,a+n) , reverse(a,a+n) , priority_queue <int> max heap , priority_queue <int, vector<int>, greater<int> > min heap;
// == > != precedence gretaer then & , << precedence greater than <= == => , 
//int chk, cnt, fl, pos, in, src, tar, val, res. dummy;  fill (myvector.begin(),myvector.begin()+4,5), freq;					
// can

double dp[3*300+1][2*300+1][301+1];
int n;
double call(int i, int j, int k)
{	
	
	double &res=dp[i][j][k];
	//cout<<i<<" "<<j<<" "<<k<<" "<<n<<" "<<res<<endl;
	if(res!=-1) return res;
	double x1=0, x2=0, x3=0, sum=i+j+k;
	if(sum==0) return 0;
	if(i) x1=call(i-1,j,k);
	if(j) x2=call(i+1,j-1,k);
	if(k) x3=call(i,j+1,k-1);
	res=n*((x1+1)*i/n+(x2+1)*j/n+(x3+1)*k/n+(n-sum)/n)/sum;
	
	return res;

}
void solve()
{
	cin>>n;
	int arr[n], sum=0;
	//int mp[4]={0,0,0,0};
	rep(i,0,n)
	{ 
		cin>>arr[i], sum+=arr[i];
	///	mp[a[i]]++;
	}
    int table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http:// goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0, j = gap; j < n; ++i, ++j) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z)); 
        } 
    } 
  
    cout<<2*table[0][n - 1]-sum; 
}
signed main()
{
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int t;
		t=1;
		while(t--)
		{
			solve();
		}
}	
