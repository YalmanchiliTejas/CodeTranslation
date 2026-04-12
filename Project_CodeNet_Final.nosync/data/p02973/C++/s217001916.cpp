#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(v) v.begin(), v.end()
const int MOD = 1e9+7;

int main(){
    FasterIO;

    int n;

    while(cin>>n){
        multiset<int>mset;
        int val;

        for(int i=0; i<n; i++){
            cin>>val;

            multiset<int>::iterator it = mset.lower_bound(val);

            if(it==mset.begin())
                mset.insert(val);

            else{
                it--;
                mset.erase(it);
                mset.insert(val);
            }
        }

        cout<<mset.size()<<endl;
    }

    return 0;
}

