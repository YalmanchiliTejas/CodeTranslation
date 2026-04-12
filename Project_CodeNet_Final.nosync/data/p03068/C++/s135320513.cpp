#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;
int main()
{
     int n,temp;
     string s;
     cin >> n >> s >> temp;
     char c;
     c = s[temp-1];
     for(int i=0;i<s.size();i++){
if(s[i] != c)s[i] = '*'; 
     }
     cout << s << endl;
     return 0;
}