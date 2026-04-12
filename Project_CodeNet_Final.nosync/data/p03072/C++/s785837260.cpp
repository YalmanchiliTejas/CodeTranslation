#include<iostream>
using namespace std;
 
int main(){
    int a, b[20], i = 0;
    cin >> a;
    while(a > i){
        cin >> b[i];
        i++;
    }
    int cnt = 1;
    int max = b[0];
    for(int i = 1;i < a;i++){
        if(max <= b[i] && b[i - 1] <= b[i]){
            cnt = cnt + 1;
        }
        if(max < b[i]){
            max = b[i];
        }
    }
    cout << cnt << endl;
}
