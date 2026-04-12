#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N;
    cin >> N;
    ll Ai;
    multiset<ll> A;
    cin >> Ai;
    A.insert(Ai);
    for(int i=1;i<N;i++){
        cin >> Ai;
        if(Ai <= *A.begin()){
            A.insert(Ai);
        }else{
            auto it = A.lower_bound(Ai);
            A.erase(--it);
            A.insert(Ai);
        }
    }
    cout<<A.size()<<endl;

    return 0;
}