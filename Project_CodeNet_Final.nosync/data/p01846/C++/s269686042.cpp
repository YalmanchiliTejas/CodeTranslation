#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
typedef long long ll;
typedef int64_t in;
using namespace std;



int main(){
    while(1){
        string s;
        vector<vector<int>> xy(9,vector<int>(9));
        vector<char> jfen;
        int a,b,c,d;
        int index=0;
        int intstr=0;
        int x=0, y=0;
        int X=0, Y=0;
        cin >> s;
        if(s == "#") break;
        cin >> a >> b >> c >> d;
        while(index < s.size()){
            if(s[index] == 'b') {
                xy[y][x] = -1;
                x++;
                index++;
            }else if(s[index] == '/'){
                y++;
                x=0;
                index++;
            }else{
                intstr = (int) s[index] - '0';
                //cout << intstr;
                for(int i=0; i<intstr; i++){
                    xy[y][x] = 0;
                    x++;
                }
                index++;
            }
        }
        //cout << index << x << y << endl;

        xy[a-1][b-1] = 0;
        xy[c-1][d-1] = -1;
        intstr = 0;
        while(Y <= y){
            if(X==x){
                if(Y==y) break;
                if(intstr != 0){
                    char st = (char) intstr + '0';
                    jfen.push_back(st);
                    intstr = 0;
                }
                jfen.push_back('/');
                X = 0;
                Y++;
                continue;
            }
            if(xy[Y][X] == -1){
                if(intstr != 0){
                    char st = (char) intstr + '0';
                    jfen.push_back(st);
                    intstr = 0;
                }
                jfen.push_back('b');
                X++;
            }else{
                intstr += 1;
                X++;
            }
        }
        if(intstr != 0){
            char st = (char) intstr + '0';
            jfen.push_back(st);
            intstr = 0;
        }
        
        for(int i=0; i<jfen.size(); i++){
            cout << jfen.at(i);
        }
        cout << endl;
    }
    return 0;
}
