#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<map>
#include<utility>
#include<cmath>
#include<tuple>
#include<string>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    for(int i=1;i<3;i++){
        if(s[0]!=s[i]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}