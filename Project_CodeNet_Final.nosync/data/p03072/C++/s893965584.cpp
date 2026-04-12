#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, num, max, cont = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> num;
        if(!i){
            max = num;
            cont++;
        }else if(num >= max){
            max = num;
            cont++;
        }
    }

    cout << cont << endl;


    return 0;

}