#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,ans=1,first;
    cin >> N;
    vector<int> inn(N);
    for(int i=0;i<N;i++){
        cin >> inn[i];
        if(i==0){
            first = inn[i];
        }else{
            ans++;
            for(int j=0;j<i;j++){
                if(inn[j]<=inn[i]){
                    continue;
                }else{
                    ans--;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}