#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
typedef long long int ll;
using namespace std;
using Graph = vector<vector<int> >;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
char c;
cin>>c;
set<char> vowel={'a','i','u','e','o'};

string ans;
if(vowel.count(c)==1) ans ="vowel";
else ans = "consonant";
cout<<ans<<endl;
//system("pause");
return 0;
}