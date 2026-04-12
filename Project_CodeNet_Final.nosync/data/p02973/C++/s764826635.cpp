#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    multiset<int> ms;
    ms.insert(a[0]);
    for(int i=1;i<N;i++){
        auto tmp=ms.lower_bound(a[i]);
        if(tmp!=ms.begin()){
            tmp--;
            ms.erase(tmp);
        }
        ms.insert(a[i]);
    }
    cout << ms.size() << endl;
}