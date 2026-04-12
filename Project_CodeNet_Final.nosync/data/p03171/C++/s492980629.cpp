#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define UB upper_bound
#define LB lower_bound
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define be(a) (a).begin(),(a).end()
#define deb(x) cout<< #x <<" "<<endl;
#define deb2(x, y) cout<< #x <<" "<< x <<endl<< #y <<" "<<y<<endl
#define fo(i, n) for(long long i=0; i<n; i++)
#define Fo(i, n, k) for(long long i=k; i<n; i++)
#define mod 1000000007
#define int long long

typedef long long ll;

void fileIO()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
 
typedef vector<pair<int, int>> vll;
typedef unordered_map<int, int> ump;



bool sortbysecdesc(const pair<int, int> &a, 
                    const pair<int, int> &b) 
{ 
    return a.second>b.second;
}

int val = -1 * (1e13);

vector<vector<int>> dp(3001, vector<int>(3001, val));

int optimal(vector<int> &a, int i, int j)
{
    int &ans = dp[i][j];
    if(ans != val) return ans;
    if(i==j) ans = a[i];
    else if(i+1 == j) ans = max(a[i], a[j]);
    else
    {
        ans =  max(a[i] + min(optimal(a, i+2, j), optimal(a, i+1, j-1)), 
                   a[j] + min(optimal(a, i+1, j-1), optimal(a, i, j-2)));
    }

    return ans;  

}



int32_t main()
{
    IOS;
    fileIO();
    int T;
    T = 1;
    //cin>>T;

    while(T--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        int X = optimal(a, 0, n-1);
        int Y = sum - X;

        cout<<X-Y<<"\n";


    }
    
    return 0;
}

