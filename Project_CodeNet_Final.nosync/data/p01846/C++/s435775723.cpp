#include <bits/stdc++.h>
using namespace std;

string S;
int A, B, C, D;

string to_line_board(string s){
    string t = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'b')
            t += 'b';
        else{
            for(int j=0; j<s[i]-'0'; j++)
                t += '.';
        }
    }
    return t;
}

vector<string> to_board(){
    vector<string> vec;
    
    string s = "";
    for(int i=0; i<S.size(); i++){
        if(S[i] == '/'){
            vec.push_back(to_line_board(s));
            s = "";
        }else{
            s += S[i];
        }
    }
    vec.push_back(to_line_board(s));
    
    return vec;
}

string to_string(vector<string> board){
    vector<string> vec;
    
    for(auto s: board){
        string t = "";
        
        int n = s.size();
        for(int i=0; i<n;){
            if(s[i] == 'b'){
                t += 'b';
                i++;
            }else{
                int cnt = 0;
                for(;i<n && s[i]=='.'; i++){
                    cnt++;
                }
                t += '0'+cnt;
            }
        }
        vec.push_back(t);
    }
    
    string res = "";
    for(int i=0; i<vec.size(); i++){
        res += vec[i];
        if(i != vec.size()-1)
            res += '/';
    }
    return res;
}

int main(){
    while(cin >> S, S!="#"){
        cin >> A >> B >> C >> D;
        A--; B--; C--; D--;
        
        auto board = to_board();
        swap(board[A][B], board[C][D]);
        cout << to_string(board) << endl;
    }
    
}