#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
using namespace std;

#define DEBUG(x) cerr << #x << " = " << x << endl

template<class T, class U> T lexical_cast(const U& from)
{ T to; stringstream ss; ss << from; ss >> to; return to; }

struct node {
    int id;
    node *prev;
    node *next;
};

int main() {
    for(int M, N; cin >> M >> N, M + N != 0; ) {
        vector<node> p(M);
        for(int i = 0; i < M; i++) {
            p[i].id = i + 1;
            p[i].prev = &p[(i - 1 + M) % M];
            p[i].next = &p[(i + 1) % M];
        }

        int number = 1;
        node *cur = &p[0];
        while(N--) {
            // DEBUG(cur->id);
            // DEBUG(number);
            string mes; cin >> mes;
            if(number % 15 == 0) {
                if(mes != "FizzBuzz") {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
            }
            else if(number % 3 == 0) {
                if(mes != "Fizz") {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
            }
            else if(number % 5 == 0) {
                if(mes != "Buzz") {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
            }
            else {
                if(mes != lexical_cast<string>(number)) {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
            }
            cur = cur->next;
            number++;
        }

        node *end = cur;
        cur = cur->next;
        vector<int> res;
        for(; cur != end; cur = cur->next) {
            res.push_back(cur->id);
        }
        res.push_back(cur->id);
        sort(res.begin(), res.end());
        for(int i = 0; i < (int)res.size() - 1; i++) {
            cout << res[i] << ' ';
        }
        cout << *res.rbegin() << endl;
    }
}