/// Author: Sarfaraz Alam
# include <bits/stdc++.h>
# define pb push_back
# define ll long long

# define fi first
# define se second
# define all(vc) vc.begin(),vc.end()
# define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
# define DEBUG
typedef unsigned long long int ull;
using namespace std;
#include<string>
#include<cmath>
const int N = 1e5 + 7;
const int mod = 1e9 + 7;


int main()
{
    speed;
    #ifdef DEBUGfd
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // DEBUG

    //Code begins
    int n;
    cin>>n;
    int a[n][26];

    for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<26; j++)
      {
        a[i][j] = INT_MAX;
      }
    }

    string s;
    for(int i = 0; i<n; i++)
    {
      cin>>s;

      for(int j = 0; j<s.size(); j++)
      {
        int k = a[i][s[j] - 'a'];
        if(k != INT_MAX)
         a[i][s[j] - 'a'] += 1;
         else
         {
           a[i][s[j] - 'a' ] = 1;
         }
      }
    }


    int f[26] ;

    for(int i = 0; i<26; i++)
    f[i] = -1;

    for(int i = 0; i<26; i++)
    {
      int min = INT_MAX;
      int dont = 0;
      for(int j = 0 ; j<n; j++)
      {
        if(a[j][i] == INT_MAX)
        {
          dont  = 1;
          break;
        }
        if(a[j][i] < min)
        min = a[j][i];
      }
      if(dont == 0)
      f[i] = min;
      else
      f[i] = INT_MAX;
    }

    int empty = 1;

    for(int i = 0; i<26; i++)
    {
      if(f[i] != INT_MAX)
      {
        char k = 'a' + i;
        cout<<string( f[i], k);
        empty = 0;
      }
    }
    //
    // for(int i = 0; i<26; i++)
    // cout<<f[i]<<" ";
    // cout<<endl;
    string w = "";
    if(empty == 1)
    cout<<w<<endl;


    return 0;
}
