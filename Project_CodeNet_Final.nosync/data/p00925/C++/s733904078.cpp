#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int calc_left_to_right(string s){
    int res = s[0] - '0';
    for(int i=1;i<s.size();i+=2){
        if(s[i] == '+'){
            res += s[i+1] - '0';
        }else{
            res *= s[i+1] - '0';
        }
    }
    return res;
}

int calc_mul_first(string s){
    stack<int> stk;
    stk.push(s[0]-'0');
    for(int i=1;i<s.size();i+=2){
        if(s[i] == '+'){
            stk.push(s[i+1]-'0');
        }else{
            int n = stk.top(); stk.pop();
            stk.push((s[i+1]-'0')*n);
        }
    }
    int res = 0;
    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }
    return res;
}

int main(){
    string expr;
    int ans;
    cin >> expr >> ans;
    int a = calc_left_to_right(expr), b = calc_mul_first(expr);
    char c;
    if(a == ans && b == ans)c = 'U';
    else if(a == ans)c = 'L';
    else if(b == ans)c = 'M';
    else c = 'I';
    cout << c << endl;

    return 0;
}

