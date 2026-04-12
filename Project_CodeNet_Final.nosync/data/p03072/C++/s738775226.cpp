
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    vector<int> H(100);
    int Ans = 1;
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> H[i];
    }
    for(int i = 1;i < N;i++){
        int count = 0;
        for(int j = 0;j < i;j++){
            if(H[i] >= H[j]){
                count++;
            }
        }
        if(count == i){
            Ans++;
        }
    }
    cout << Ans << endl;
}