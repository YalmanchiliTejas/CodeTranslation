#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    string in;
    vector< stack<char> > vec_st;
    int p;
    char c;
    
    cin >> n;
    vec_st.resize(n);
    
    while (1) {
        cin >> in;
        if (in == "quit") {
            break;
        } else if (in == "push"){
            cin >> p >> c;
            vec_st[p - 1].push(c);
        } else if (in == "pop"){
            cin >> p;
            cout << vec_st[p - 1].top() << endl;
            vec_st[p - 1].pop();
        } else if (in == "move"){
            int p2;
            
            cin >> p >> p2;
            c = vec_st[p - 1].top();
            vec_st[p - 1].pop();
            vec_st[p2 - 1].push(c);
        }
    }
    
    return 0;
}