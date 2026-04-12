#include <bits/stdc++.h>
using namespace std;

int main(){
    int h, w, i, n = 0;
    char c;
    cin >> h >> w;
    for(i=0; i<h*w; i++){
        cin >> c;
        if(c == '#'){
            n++;
        }
    }
    if(n == h+w-1){
        cout << "Possible";
    }else{
        cout << "Impossible";
    }
    return 0;
}