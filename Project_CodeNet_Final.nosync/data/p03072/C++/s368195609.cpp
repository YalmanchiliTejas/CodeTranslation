#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++)cin >> a[i];
    int sum = 1;
    for(int i = 1;i < n;i++){
        bool check = true;
        for(int j = 0;j < i;j++){
            if(a[j] > a[i])check = false;
        }
        if(check == true)sum++;
    }
    cout << sum;
}