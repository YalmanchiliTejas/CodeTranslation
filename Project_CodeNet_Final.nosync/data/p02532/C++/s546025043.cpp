#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n,value,va;
    char block;
    string s;
    cin >> n;
    cin.ignore();
    vector < stack <char> > st;
    st.resize(n);
    while(cin >> s && s != "quit"){
        if(s == "push"){
            cin >> value >> block;
            st[value-1].push(block);
        }
        else if(s == "move"){
            cin >> value >> va;
            st[va-1].push(st[value-1].top());
            st[value-1].pop();
        }
        else{
            cin >> value;
            cout << st[value-1].top() << endl;
            st[value-1].pop();
        }
    }
}