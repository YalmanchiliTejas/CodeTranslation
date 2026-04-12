#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};


int main(){
    int N;
    cin>>N;
    vector<int> a(N);

    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    vector<int> tops;
    tops.push_back(a[0]);
    for(int i=1;i<N;i++){
        auto iter=lower_bound(tops.rbegin(),tops.rend(),a[i]);
        int comp=tops.rend()-iter;
        if(comp==tops.size()) tops.push_back(a[i]);
        else{
            tops[comp]=a[i];
        }

    }
    cout<<tops.size()<<endl;
/*
    vector<int> test(2);
    test[0]=5; test[1]=3;
    cout<<test.rend()-lower_bound(test.rbegin(),test.rend(),4)<<endl;

*/

    return 0;
}
