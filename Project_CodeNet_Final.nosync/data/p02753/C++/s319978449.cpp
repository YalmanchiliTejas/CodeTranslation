#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
   string s;
   cin>>s;
   sort(s.begin(),s.end());
   if(s[0]==s[2])cout<<"No";
   else cout<<"Yes";

    return 0;
}
