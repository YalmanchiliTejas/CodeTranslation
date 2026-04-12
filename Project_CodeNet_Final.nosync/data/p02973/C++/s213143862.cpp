#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int, int> mp;
    int N;
    int ans = 0;
    cin >> N;
    mp[-1] = 1;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        auto ptr = mp.lower_bound(A);
        ptr--;
        if(ptr->first == -1){
            //cout << i << endl;
            if(mp.count(A) != 0){
                mp[A]++;
            }else{
                mp[A]=1;
            }
            ans++;
        }else{
            int m = ptr->first;
            mp[m]--;
            if(mp[m] == 0){
                mp.erase(m);
            }
            if(mp.count(A) != 0){
                mp[A]++;
            }else{
                mp[A] = 1;
            }
        }
    }
    cout << ans << endl;
}