#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector <int>H(N);
    for(int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
    
    int ans = 0;
    int maxHeight = -1;
    for (int i=0; i<N; i++)
    {
        if(maxHeight <=H[i]){
            ans++;
            maxHeight = H[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}
