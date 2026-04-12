#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n ;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i] ;
    }

    int cnt = 0;
    int a = 0;
    int max = h[0];

    for(int i = 0; i  < n; i++){
        for(int j = 0; j < i; j++){
            if(max > h[i]){
                cnt++;
            }else{
                max = h[i];
            }
        }
        if(cnt == 0){
            a++;
        }
        cnt=0;
    }

    cout << a << endl;

}