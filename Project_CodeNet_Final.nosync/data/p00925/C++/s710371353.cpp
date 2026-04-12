#include<iostream>
#include<string>
#include<stack>

using namespace std;

typedef long long ll;

class MultiFirst{
    public: 

    string s;
    size_t i;
    MultiFirst(string s): s(s){}
    ll parse(){
        i = 0;
        return expr(&i);
    }

    private:

    ll num(size_t *i){
        return stoll(s.substr(*i, 1));
    }

    ll term(size_t *i){
        ll ret = num(i); (*i)++;
        while(*i < s.length() && s[*i] == '*'){
            (*i)++; // *
            ret *= num(i);
            (*i)++;
        }
        return ret;
    }

    ll expr(size_t *i){
        ll ret = term(i);
        while(*i < s.length() && s[*i] == '+'){
            (*i)++; // +
            ret += term(i);
        }
        return ret;
    }
};

class LeftToRight{
    public: 

    string s;
    size_t i;
    LeftToRight(string s): s(s){}
    ll parse(){
        stack<int> st;
        st.push(s[0]-'0');
        for(size_t i=1;i<s.length();i++){
            if(st.top() < 0){
                if('0' <= s[i] && s[i] <= '9'){
                    int op = st.top(); st.pop();
                    int a = st.top(); st.pop();
                    int b = s[i] - '0';
                    if(op == -1){
                        st.push(a+b);
                    }else{
                        st.push(a*b);
                    }
                }
            }else{
                if('0' <= s[i] && s[i] <= '9'){
                    st.push(s[i]-'0');
                }else if(s[i] == '+'){
                    st.push(-1);
                }else{
                    st.push(-2);
                }
            }
        }
        return st.top();
    }
};

int main(){
    string s;
    ll bob;
    cin >> s >> bob;

    ll m = MultiFirst(s).parse();
    ll l = LeftToRight(s).parse();

    if(bob == m){
        if(bob == l){
            cout << 'U' << endl;
        }else{
            cout << 'M' << endl;
        }
    }else{
        if(bob == l){
            cout << 'L' << endl;
        }else{
            cout << 'I' << endl;
        }
    }
}
