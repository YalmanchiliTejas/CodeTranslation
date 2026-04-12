#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;

    cin >> n;

    int h[n];

    for(int i=0; i<n; i++){
        cin >> h[i]; 
    }

    int r = 0;
    int flag;



    for(int i=0; i<n;i++){
        flag = 1;
        for(int j=0;j<i;j++){
            if(h[j] > h[i]){
                flag = -1;
            }
        }
        if(flag == 1){
            r++;
        }
    }

    cout << r << endl;




}