#include <iostream>
#include <stack>

using namespace std;


int main()
{
    int n;

    cin >> n;

    while(n!=0) {
        int color;
        stack<pair<int,int> > board; // color, length

        for(int i=0; i<n; ++i) {
            cin >> color;
            if(i%2==0) {
                if(board.empty()) {
                    board.push(make_pair(color,1));
                } else {
                    pair<int,int> b=board.top();
                    if(b.first!=color) {
                        board.push(make_pair(color,1));
                    } else {
                        board.pop();
                        board.push(make_pair(color,b.second+1));
                    }
                }
            } else {
                pair<int,int> b=board.top(); board.pop();
                if(board.empty()||b.first==color) {
                    board.push(make_pair(color,b.second+1));
                } else {
                    pair<int,int> bb=board.top(); board.pop();
                    board.push(make_pair(color,bb.second+b.second+1));
                }
            }
        }

        int ans=0;
        while(!board.empty()) {
            pair<int,int> b=board.top(); board.pop();
            if(b.first==0) ans+=b.second;
        }

        cout << ans << endl;

        cin >> n;
    }
    return 0;
}