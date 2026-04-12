#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct List {
    int prev, next;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m, n;
    while(cin >> m >> n && (m | n)){

        List l[1010];
        l[0].prev = m - 1;
        l[0].next = 1;
        for(int i = 1; i < m - 1; ++i){
            l[i].prev = i - 1;
            l[i].next = i + 1;
        }
        l[m - 1].prev = m - 2;
        l[m - 1].next = 0;

        int now = 0;
        bool check[1010];
        for(int i = 0; i < m; ++i){
            check[i] = true;
        }

        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            string str;
            cin >> str;
            bool b1 = (i % 3 == 0 && i % 5 == 0 && str == "FizzBuzz");
            bool b2 = (i % 3 == 0 && i % 5 != 0 && str == "Fizz");
            bool b3 = (i % 3 != 0 && i % 5 == 0 && str == "Buzz");
            bool b4 = (i % 3 != 0 && i % 5 != 0 && str == to_string(i));
            if(cnt < m - 1){
                if(b1 || b2 || b3 || b4){
                    now = l[now].next;
                }
                else {
                    cnt++;
                    check[now] = false;
                    l[l[now].prev].next = l[now].next;
                    l[l[now].next].prev = l[now].prev;
                    now = l[now].next;
                }
            }
        }

        //cout << cnt << endl;

        bool check2 = false;
        for(int i = 0; i < m; ++i){
            if(check[i]){
                if(check2){
                    cout << ' ';
                }
                cout << i + 1;
                check2 = true;
            }
        }
        cout << endl;
    }

    return 0;
}