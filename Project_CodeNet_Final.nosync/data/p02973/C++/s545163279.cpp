#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <set>
using namespace std;

int main(){
    int N;
    cin>>N;
    multiset<int> S;
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        auto ite = S.lower_bound(a);
        if(ite!=S.begin()) S.erase(--ite);
        S.insert(a);
    }
    cout<<S.size()<<endl;
    return 0;
}