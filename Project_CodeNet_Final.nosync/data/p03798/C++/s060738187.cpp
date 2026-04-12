#include <iostream>
#include <string>

using namespace std;


long n;
string s;

bool solve(bool first, bool second){
    bool place[n];
    long current = 0;

    place[0] = first;
    place[1] = second;

    while(current < n){
        if (current == 0){
            if (s[current] == 'o')
                place[n-1] = !(first ^ second);
            else
                place[n-1] = (first ^ second);
        }
        if (current == n-2){
            if (s[current] == 'o'){
                if (!(place[current-1] ^ place[current]) != place[current+1])
                    return false;
            }
            if (s[current] == 'x'){
                if ((place[current-1] ^ place[current]) != place[current+1])
                    return false;
            }
        }
        if (current == n-1){
            if(s[current] == 'o'){
                if(place[current] && (place[current-1] ^ place[0]))
                    return false;
                if((!place[current]) && (!(place[current-1] ^ place[0])))
                    return false;
            }else{
                if(place[current] && (!(place[current-1] ^ place[0])))
                    return false;
                if((!place[current]) && (place[current-1] ^ place[0]))
                    return false;
            }
        }
        if(current > 0 && current < n-2){
            if(s[current] == 'o'){
                if(place[current] == true)
                    place[current+1] = place[current-1];
                else
                    place[current+1] = !place[current-1];
            } else{
                if(place[current] == true)
                    place[current+1] = !place[current-1];
                else
                    place[current+1] = place[current-1];
            }
        }
        current++;
    }
    for(int i=0;i<n;i++){
        if(place[i] == true){
            cout << 'S';
        }else{
            cout << 'W';
        }
    }
    cout << endl;
    return true;
}

int main(){
    cin >> n >> s;

    bool place[n];
    for(int i= 0;i<n;i++){
        place[i] = true;
    }

    bool flag = false;
    //SS
    flag = solve(true,true);
    if (flag)
        return 0;
    //SW
    flag = solve(true,false);
    if (flag)
        return 0;
    //WS
    flag = solve(false,true);
    if (flag)
        return 0;
    //WW
    flag = solve(false,false);
    if (flag)
        return 0;
    cout << -1 << endl;
}