#include<bits/stdc++.h>
#include<bitset>

using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)

typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 5e5 + 10;

vector<int> g[N];
bool viss[N];
int vis[N];

// Normal DFS
void dfs(int curr, int par)
{
  for(auto x: g[curr])
    if(x != par)
      dfs(x, curr);
}

// DFS with visiting status
void dfs1(int curr, int par)
{
  viss[curr] = 1;
  for(auto x: g[curr])
    if(!viss[x])
      dfs1(x, curr);
}

// DFS with strongly connected component
void dfs2(int curr, int par, int num)
{
  vis[curr] = num;
  for(auto x: g[curr])
    if(vis[x] == 0)
      dfs2(x, curr, num);
}

// XOR from 0 to n
ll fxor(ll n)
{
  if(n < 0) return 0;
  if(n % 4 == 3) return 0;
  else if(n % 4 == 0) return n;
  else if(n % 4 == 1) return n^(n-1);
  else if(n%4 == 2) return n^(n-1)^(n-2);
}

// Power in logn with mod 1000000007
llt ppow(llt x, llt y)
{
  llt res = 1;
  while(y > 0){
    if(y&1)
      res = (res * x)%M;
    y = y >> 1;
    x = (x * x)%M;
  }
  return res;
}

// Factorial with dp
llt factdp[N];
llt fact(llt x)
{
  if(x == 0) return 1;
  if(x == 1) return 1;
  if(factdp[x] != -1) return factdp[x];
  return factdp[x] = (x*fact(x-1))%M;
}

// String return to base b
string ansConv ="";
void convert10tob(llt N, int b)
{
     if (N == 0)
        return;
     int x = N % b;
     N /= b;
     if (x < 0)
        N += 1;
     convert10tob(N, b);
     ansConv += to_string(x);
     return;
}

// Convert string to num wiht base b
llt convertstrtob(string a, int b)
{
  llt aa = 0;
  llt mul = 1;
  for(int i=a.length()-1; i>=0; i--)
  {
    int curr = a[i] - '0';
    aa += (curr * mul);
    mul *= b;
  }
  return aa;
}

// Union Find algo with array
// Find()
int findpar(int curr, int arr[])
{
  while(arr[curr] != curr) curr = arr[curr];
  return curr;
}
// Union()
void Union(int b, int spa, int arr[])
{
  while(arr[b] != b)
  {
    int c = arr[b];
    arr[b] = spa;
    b = c;
  }
  arr[b] = spa;
}

// Main Code
int n;
string s;
bool findans(char ans[])
{
  char aa;
  if(ans[0] == 'S')
  {
    if(ans[1] == 'S')
    {
      if(s[0] == 'o') aa = 'S';
      else aa = 'W';
    }
    else
    {
      if(s[0] == 'o') aa = 'W';
      else aa = 'S';
    }
  }
  else
  {
    if(ans[1] == 'S')
    {
      if(s[0] == 'o') aa = 'W';
      else aa = 'S';
    }
    else
    {
      if(s[0] == 'o') aa = 'S';
      else aa = 'W';
    }
  }
  rep(i, 1, n)
  {
    if(ans[i] == 'S')
    {
      if(ans[i-1] == 'S')
      {
        if(s[i] == 'o') ans[i+1] = 'S';
        else ans[i+1] = 'W';
      }
      else
      {
        if(s[i] == 'o') ans[i+1] = 'W';
        else ans[i+1] = 'S';
      }
    }
    else
    {
      if(ans[i-1] == 'S')
      {
        if(s[i] == 'o') ans[i+1] = 'W';
        else ans[i+1] = 'S';
      }
      else
      {
        if(s[i] == 'o') ans[i+1] = 'S';
        else ans[i+1] = 'W';
      }
    }
  }
  return ((aa == ans[n-1])&&(ans[n] == ans[0]));
}

void printarr(char ans[])
{
  for(int i=0; i<n;i++)
    cout<<ans[i];
  cout<<endl;
}
int main()
{

  cin>>n;

  cin>>s;
  char ans1[n+1];
  char ans2[n+1];
  char ans3[n+1];
  char ans4[n+1];
  ans1[0] = 'S'; ans1[1] = 'S';
  ans2[0] = 'W'; ans2[1] = 'S';
  ans3[0] = 'S'; ans3[1] = 'W';
  ans4[0] = 'W'; ans4[1] = 'W';
  if(findans(ans1)) printarr(ans1);
  else if(findans(ans2)) printarr(ans2);
  else if(findans(ans3)) printarr(ans3);
  else if(findans(ans4)) printarr(ans4);
  else puts("-1");
  return 0;
}
