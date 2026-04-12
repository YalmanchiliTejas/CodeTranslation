#import<bits/stdc++.h>
#define sorted(vector) sort(vector.begin(),vector.end())
#define append(a) push_back(a)
#define int(a) stoi(a)
#define str(a) to_string(a)
using namespace std;


int a,b,c,x,g;
string s,t,r;

int main(void){
    cin>>s>>t>>r;
    auto a = stoi(s+t+r);
    if (a%4==0) puts("YES");
    else puts("NO");
}