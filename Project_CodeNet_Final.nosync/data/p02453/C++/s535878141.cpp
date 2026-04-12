#include <iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int>::iterator it;
    for(int i=0;i<n;i++){ cin>>v[i];}
    int q;cin>>q;
    while(q--){
        int a;cin>>a;
        it=lower_bound(v.begin(),v.end(),a);
        cout<<it-v.begin();
        cout<<"\n";
    }

}


