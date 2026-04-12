#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <algorithm>
#define rep(i, n) for(int i = 0; i < n; i++)
#define For(i, m, n) for(int i = m;i < n;i++)

using namespace std;


int main(){
    int n;
    cin >> n;
    int arg[n];
    int count = 0;

    for(int i = 0; i < n; i++){
        cin >> arg[i];
    }

    if(sizeof(arg) == 1){
        
    } else if(sizeof(arg) == 2){
        if(arg[1] < arg[0]){
            count++;
        }
    } else {

        for(int i = 1; i < n; i++){
            for(int j = 0; j < n + 1; j++){
                if(j == i){
                    count++;
                } else {
                    if(arg[j] > arg[i]){
                        break;
                    }
                }
            }
        }

    }
    count++;
    cout << count << endl;

}