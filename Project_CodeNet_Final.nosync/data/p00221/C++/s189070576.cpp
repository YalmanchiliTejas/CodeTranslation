#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int N, Q;

    while(cin >> N >> Q, N) {
        vector<int> alive(N);
        iota(alive.begin(), alive.end(), 1);

        int person = 0, alive_cnt = N, game_end = false;
        for(int word=1; word<=Q; word++) {
            string s; cin >> s;

            if(game_end) continue;

            bool ok = true;
            if     (word % 15 == 0) {
                if(s != "FizzBuzz") ok = false;
            }
            else if(word %  3 == 0) {
                if(s != "Fizz"    ) ok = false;
            }
            else if(word %  5 == 0) {
                if(s != "Buzz"    ) ok = false;
            }
            else {
                if(s != to_string(word)) ok = false;
            }

            if(!ok) {
                alive.erase(alive.begin() + person);
                person %= alive.size();
                alive_cnt--;
                if(alive_cnt == 1) game_end = true;
            }
            else {
                person = (person + 1) % alive.size();
            }
        }

        for(size_t i=0; i<alive.size(); i++) {
            cout << alive[i] << " \n"[i+1==alive.size()];
        }
    }
    return 0;
}
