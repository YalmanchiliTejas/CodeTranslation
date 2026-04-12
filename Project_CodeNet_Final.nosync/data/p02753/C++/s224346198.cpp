#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef vector<int> iv;
typedef vector<bool> bv;
typedef vector<string> sv;
typedef vector<long long int> llv;
typedef vector<double> dv;
#define debug_ printf("OK\n")

#define sor_(vec) sort(vec.begin(),vec.end())
#define rev_(vec) reverse(vec.begin(),vec.end())
#define rep(i,n) for(int i=0;i<static_cast<int>(n);i++)
#define reps(i,n,s) for(int i=static_cast<int>(s);i<static_cast<int>(n);i++)
#define isposi(num) if(num>0)

const long long mod = 1000000007;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::string str;
    cin>>str;
    if(str.find("A")!=std::string::npos&&str.find("B")!=std::string::npos)printf("Yes");
    else printf("No");
    return 0;
}
