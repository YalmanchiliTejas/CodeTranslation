#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int hotels[N];
    for(int i = 0;i < N;i++){
        cin >> hotels[i];
    }
    int cnt = 1;
    int MAX = hotels[0];
    for(int i = 1;i < N;i++){
        if(MAX <= hotels[i]){
            cnt++;
            MAX = hotels[i];
        }
    }
    cout << cnt << endl;

    return 0;
}
