#include <bits/stdc++.h>
#define llint long long int
#define ldouble long double

//setprecision()<<

using namespace std;

int main() {
    int N,K;
    string S;
    cin>>N>>S>>K;
    char x=S.at(K-1);
    for(int i=0;i<S.size();i++){
        if(x!=S.at(i)){
            S.at(i)='*';
        }
    }

    cout<<S<<endl;
return 0;
}