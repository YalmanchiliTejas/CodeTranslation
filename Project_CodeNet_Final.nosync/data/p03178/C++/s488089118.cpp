#include<bits/stdc++.h>
#define ll long long
#define dl double
using namespace std;

//***********************************************************************
int MAXNUM = 5e3+5;
vector <int>vis(MAXNUM);
vector<int> pr;
void sieve() {
	pr.push_back(2);
	for(ll i=3;i<MAXNUM;i+=2) if(!vis[i]) {
		pr.push_back(i);
		for(ll j=i*i;j<MAXNUM;j+=2*i) vis[j]=true;
	}
}
//************************************************************************
ll mod=1000000007;


 // not correct but found logic ,
 //if one digit is gone then, found no. of lower numbers but adjust the remainder
 // dp should be 10^7


 
void solve()
{
   
    string s;
   
    cin >>s;
  
    reverse(s.begin(),s.end());
   // cout << "check   :  " << endl;
    int d;
    int si=s.size();
     // cout << s << endl;
    cin >>d;
    //int dp[10001][10][101];
    //int rn[10001][101];
    //cout << "check 1" << endl;
    vector<vector<vector<ll>>> dp(10001);
   // cout << "check 2 " << endl;
    for(int i=0;i<10001;i++)
    {
        dp[i].resize(10);
        //rn[i].resize(101);
        //cout << "check 1" << endl;
        for(int j=0;j<10;j++)
        {
            dp[i][j].resize(101);
            for(int k=0;k<101;k++)
            {
                dp[i][j][k]=0;
                
            }
        }
        //cout << "check 2" << endl;
        /*for(int j=0;j<101;j++)
        {
            rn[i][j]=0;
        }*/
        //cout << "check 4 " << endl;
    }
    dp[1][0][0]++;
   // cout << " check 2" << endl;
   
   
   
   // base case
    for(int i=1;i<10;i++)

    {
        for(int j=0;j<d;j++)
        {
            dp[1][i][j]=dp[1][i-1][j];
            //cout << "dp 1 " <<i <<" " << j << " :"<< dp[1][i][j] << endl;
        }
        dp[1][i][i%d]++;
    }
    /* for(int i=1;i<10;i++)
    {
        rn[1][i%d]++;
        dp[1][i]=dp[1][i-1];
        if(i%d==0)
        {
            dp[1][i]++;
        }
        cout << dp[1][i] << " ";
    }*/



//cout << endl;
//cout << "check 3" << endl;
    // filling the dp matrix

    for(int i=2;i<=si;i++)
    {
        //dp[i][0]=dp[i-1][9];
        for(int k=0;k<d;k++)
        {
            dp[i][0][k]=dp[i-1][9][k];
           // cout << "dp " <<i <<" " << "0"<< " " << k<<" :"<< dp[i][0][k] << endl;
        }


        for(int j=1;j<10;j++)
        {
            //dp[i][j]=(dp[i][j-1]+rn[i-1][(d-j%d)%d])%mod;
            
            for(int k=0;k<d;k++)
            {
                dp[i][j][k]=(dp[i][j-1][k]+dp[i-1][9][(d+k-j%d)%d])%mod;
                // cout << "dp " <<i <<" " << j << " " << k<<" :"<< dp[i][j][k] << endl;
                //rn[i][(k+j)%d]=(rn[i][(k+j)%d]+rn[i-1][k])%mod;
            }
            //cout << dp[i][j] <<" ";
        }
        /*for(int k=0;k<d;k++){
        rn[i][k]+=rn[i-1][k]%mod;
        rn[i][k]%=mod;
        }
        cout << endl;
        */

    }
    /*for(int j=0;j<d;j++)
        cout<< rn[1][j] <<" ";
        cout << endl;
    for(int i=2;i<=si;i++)
    {
        for(int j=0;j<d;j++)
        cout<< rn[i][j] <<" ";
        cout << endl;
    }*/
    
//cout << " check 4 " << endl;
    //finding the answer

    ll ans=0;
    ll sum=0;
    for(int i=si;i>0;i--)
    {
        char ch=s[i-1];
        ll x=(int)ch-48;
        //cout << "x:"<<x <<"sum :" << sum << endl;
        if(x!=0)
        {
        ans+=dp[i][x-1][(d-sum)%d]%mod;
        ans%=mod;
        //cout <<"ans :" <<ans<< endl;
        if((d-sum)%d==0)
        {
            ans=(ans-1+mod)%mod;
        }
       // cout <<"ans :" <<ans<< endl;
        if(x%d==(d-sum)%d)
        ans=(ans+1)%mod;
        //cout <<"ans :" <<ans<< endl;
        }
        sum=(sum+x)%d;
    }
    cout << ans << endl;
}


int main()
{ 
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	ll t;
	//cin >> t;
	t=1;
	while(t--)
	{
        //cout << "check" << endl;
		solve();
	}

	return 0;
}