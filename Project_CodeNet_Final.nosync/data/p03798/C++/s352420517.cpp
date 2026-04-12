#include <iostream>

using namespace std;
int circle[100002] = {};
string s;

void func(int i){
    // sheep : 1  wolf : -1
    if((s[i-1] == 'o' && circle[i-1] == 1) ||(s[i-1] == 'x' && circle[i-1] == -1))circle[i] = circle[i-2];
    else{circle[i] = -circle[i-2];}
}

int main(){
    int n;
    cin >> n;
    cin >> s;
    s = s + s[0];
    circle[0] = 1;circle[1] = 1;
    for(int i = 2;i <= n+1; i++){
        func(i);
    }
    if(circle[0] == circle[n] && circle[1]==circle[n+1]){
        for(int i = 0; i < n; i++){
            if(circle[i]==1)cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }

    circle[0] = 1;circle[1] = -1;
    for(int i = 2;i <= n+1; i++){
        func(i);
    }
    if(circle[0] == circle[n] && circle[1]==circle[n+1]){
        for(int i = 0; i < n; i++){
            if(circle[i]==1)cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }

    circle[0] = -1;circle[1] = -1;
    for(int i = 2;i <= n+1; i++){
        func(i);
    }
    if(circle[0] == circle[n] && circle[1]==circle[n+1]){
        for(int i = 0; i < n; i++){
            if(circle[i]==1)cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }

    circle[0] = -1;circle[1] = 1;
    for(int i = 2;i <= n+1; i++){
        func(i);
    }
    if(circle[0] == circle[n] && circle[1]==circle[n+1]){
        for(int i = 0; i < n; i++){
            if(circle[i]==1)cout << 'S';
            else cout << 'W';
        }
        cout << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}