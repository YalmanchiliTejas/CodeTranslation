// answer is number of minimum increasing subsequence or, length of longest non-increasing subsequence
#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+100;
int main ()
{
    int N;cin >> N;
    multiset<int>S;
    for(int i=0;i<N;i++){
        int x;cin >> x;
        auto it = S.lower_bound(x);
        if(it==S.begin()){
                S.insert(x);
        }
        else{
            it--;
            S.erase(it);
            S.insert(x);
        }
    }
    cout<<S.size()<<endl;
    return 0;
}
