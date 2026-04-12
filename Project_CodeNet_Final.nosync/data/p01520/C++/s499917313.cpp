#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, t, e; cin>>n>>t>>e;
    vector<int> x(n);
    for(int i=0; i<n; i++) cin>>x[i];

    for(int i=0; i<n; i++){
        for(int j=0; ; j++){
            if(t + e < j * x[i]) break;

            if(t - e <= j * x[i] && j * x[i] <= t + e){
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
}
