#include <bits/stdc++.h>

using namespace std;

string str;
int n;

int calcM(int pos)
{
    stack <int> st;
    st.push(str[pos] - '0');
    for (int i = pos + 1; i < str.length(); i++){
        if (str[i] == '+'){
            continue;
        }
        else if (str[i] == '*'){
            int a = st.top(); st.pop();
            i++;
            a *= (str[i] - '0');
            st.push(a);
        }
        else {
            st.push(str[i] - '0');
        }
    }
    
    int ret = 0;
    for (int i = 0; !st.empty(); i++){
        ret += st.top();
        st.pop();
    }
    return ret;
}

int calcL(int pos)
{
    stack <int> st;
    st.push(str[pos] - '0');
    for (int i = pos + 1; i < str.length(); i++){
        if (str[i] == '+'){
            int a = st.top(); st.pop();
            i++;
            a += (str[i] - '0');
            st.push(a);
        }
        else if (str[i] == '*'){
            int a = st.top(); st.pop();
            i++;
            a *= (str[i] - '0');
            st.push(a);
        }
    }
    
    return st.top();
}

int main(void)
{
    cin >> str >> n;
    
    int retM = calcM(0);
    int retL = calcL(0);
    
    if (retM == n && retL != n){
        cout << "M" << endl;
    }
    else if (retM != n && retL == n){
        cout << "L" << endl;
    }
    else if (retM == n && retL == n){
        cout << "U" << endl;
    }
    else {
        cout << "I" << endl;
    }
    
    
    return 0;
    
}