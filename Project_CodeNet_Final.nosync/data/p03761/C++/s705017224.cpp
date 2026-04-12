#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    int ch[150] = {};
    int n, n1;
    cin>>n;
    n1 = n;
    vector<string>str;
    while(n1--)
    {
        string s;
        cin>>s;
        for(int i = 0; i<s.size(); i++)
        {
            ch[s[i]]++;
        }
        str.push_back(s);
    }
   vector<char> vec;
   for(int i = 97; i<=122; i++)
   {
       if(ch[i]>=n)
       {   char c = i;
           vec.push_back(c);
       }
   }

    for(int k = 0; k<vec.size(); k++)
   {   ll mi = INT_MAX;
            int i = 0;
       char check = vec[k];
       for(i = 0; i<n; i++)
       {
           ll cnt = 0;
           string s = str[i];
           for(int j = 0; j<s.size(); j++)
           {
               if( s[j] == check) cnt++;
           }
           mi = min(mi, cnt);
       }
       //cout<<mi<<endl;
       while(mi--)
       {
           cout<<check;
       }
   }
   return 0;
}

