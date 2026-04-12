#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, ans=0;
    cin >> N;
    vector<int> hight(N);
    
    for (int i=0; i<N; i++){
        cin >> hight.at(i);
    }
    int p=0;
    //iで対象、ｋで前全部
    for (int i=0; i<N; i++){
        for (int k=0; k<=i; k++){
            if (hight.at(i) >= hight.at(k)){
                p++;
            }
            
        }

        if (p == i+1){
            ans++;
        }
      p=0;
    }
    cout << ans << endl;
}
