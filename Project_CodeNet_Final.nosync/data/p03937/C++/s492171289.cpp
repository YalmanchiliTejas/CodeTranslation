#include <bits/stdc++.h> 

using namespace std;

int main(){
    int h, w, tot = 0;
    cin >> h >> w;
    string temp;
    for(int one = 0; one < h; one++){
        cin >> temp;
        for(int two = 0; two < w; two++){
            if(temp[two] == '#'){tot++;}
        }
    }
    if(tot == h+w-1){cout << "Possible";}
    else{cout << "Impossible";}
}