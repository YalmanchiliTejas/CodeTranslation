#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int a[100005]; //0 sheep, 1 wolf

bool able(){
    for(int i = 2; i < n; i++){
        if(a[i - 1] == 0){
            if(s[i - 1] == 'o') a[i] = a[i - 2];
            else a[i] = 1 - a[i - 2];
        }
        else{
            if(s[i - 1] == 'o') a[i] = 1 - a[i - 2];
            else a[i] = a[i - 2];
        }
    }
    bool f, g;
    if(a[n - 1] == 0){
        if(s[n - 1] == 'o') f = (a[0] == a[n - 2]);
        else f = (a[0] == 1 - a[n - 2]);
    }
    else{
        if(s[n - 1] == 'o') f = (a[0] == 1 - a[n - 2]);
        else f = (a[0] == a[n - 2]);
    }
    if(a[0] == 0){
        if(s[0] == 'o') g = (a[n - 1] == a[1]);
        else g = (a[1] == 1 - a[n - 1]);
    }
    else{
        if(s[0] == 'o') g = (a[1] == 1 - a[n - 1]);
        else g = (a[1] == a[n - 1]);
    }
    return f && g;
}

int main()
{
    cin >> n >> s;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[0] = i;
            a[1] = j;
            if(able()){
                for(int i = 0; i < n; i++){
                    if(a[i] == 0) cout << 'S';
                    else cout << 'W';
                }
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}