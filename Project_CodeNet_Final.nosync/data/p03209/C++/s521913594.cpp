  #include<bits/stdc++.h>
  using namespace std;
  #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  #define endl "\n"
  #define all(v) v.begin(),v.end()
  #define f first
  #define s second
  #define PB push_back
  #define MP make_pair
  #define double long double
  #define trace1(x)                cerr<<#x<<": "<<x<<endl
  #define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
  #define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
  #define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
  #define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
  #define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
  #define cases int testcases;cin>>testcases; while(testcases--)
  #define MOD 998244353
  #define N 2000005
  #define INF 1000000000000
  #define eps 1e-6
  #define int long long


string brute(int n)
{
  if(n == 0)
  {

    return "P";
  }
  else return ("B" + brute(n-1) + "P" + brute(n-1)+ "B");
}


int b[N],p[N];



int32_t main()
{



    int n,x;
    cin >> n >> x;

    b[0] = 1;
    p[0] = 1;

    for(int i = 1; i <= n; i++)
    {
      b[i] = b[i-1]*2 + 3;
      p[i] = p[i-1]*2 + 1;
    }

    int ans = 0;

    x--;

    for(int i = n; i >= 0; i--)
    {
      if(x == 0)
        {
          if(i == 0)
            {
              ans++;
              
            }
            break;
        }
        else if(x == (b[i] -1)/2)
        {
          ans += p[i-1] + 1;
          break;
        }
        else if(x == b[i] - 1)
        { 
          ans += p[i];
          break;
        }
        else if(x <(b[i] -1)/2 )
        {
          x--;
        }
        else
        {
          x-= b[i-1] + 2;
          ans += p[i-1] + 1;
         }
    }



    cout << ans;




    return 0;
}