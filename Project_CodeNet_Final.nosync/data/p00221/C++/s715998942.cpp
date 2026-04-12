#include <bits/stdc++.h>
using namespace std;

string getNumStr(int i){
    if(i == 0){
        return "0";
    }

    string ans = "";

    stack<char> c;

    while(i > 0){
        c.push((i % 10) + '0');
        i /= 10;
    }

    while(!c.empty()){
        ans.push_back(c.top());
        c.pop();
    }

    return ans;
}

string fizz(int i){
    if(i % 3 == 0 && i % 5 == 0){
        return "FizzBuzz";
    }

    if(i % 3 == 0){
        return "Fizz";
    }

    if(i % 5 == 0){
        return "Buzz";
    }

    return getNumStr(i);
}

int main(){
    int n, m;

    while(cin >> m >> n, m > 0 && n > 0){
        int now = 0;
        int ydk = m;

        int life[1010] = {};

        string s;

        string t[10010];
        for(int i = 0;i < n;i++){
            cin >> t[i];
        }

        for(int i = 0;i < n;i++){
            s = t[i];
            while(life[now] == 1) now = (now+1)%m;
            if(s != fizz(i+1)){
                life[now] = 1;
                ydk--;
                if(ydk == 1){
                    break;
                }
            }
            now = (now+1) % m;
        }

        queue<int> ans;

        for(int i = 0;i < m;i++){
            if(life[i] == 0){
                ans.push(i+1);
            }
        }

        while(!ans.empty()){
            cout << ans.front();
            ans.pop();
            if(ans.empty()){
                cout << endl;
            }else{
                cout << " ";
            }
        }
    }
    return 0;
}






