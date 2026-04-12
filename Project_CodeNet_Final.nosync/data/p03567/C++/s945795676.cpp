#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int INF=0x3f3f3f3f;

int main(){
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len-1;i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
