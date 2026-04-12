#include <iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> v;
    int b=0;
    int tn=n;
    for(int i=0;i<n;i++){
        b=(b<<1|1);
        v.push_back(i);
    }
    for(int i=0;i<=b;i++){
        cout<<i<<":";
        int ti=i;
        for(int i=0;i<n;i++){
            if(ti&1){
                cout<<" "<<v[i];
            }
            ti>>=1;
        }
        cout<<"\n";
    }
}



