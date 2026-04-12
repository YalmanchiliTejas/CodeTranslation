#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int tmp = a[0];
    int count = 0;
    int flag = 0;
    for(int i = 0; i < n; i++){
        flag = 0;
        for(int j = 0; j < i; j++){
            if(a[i] < a[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            count++;
        }
    }

    cout << count << endl;
}