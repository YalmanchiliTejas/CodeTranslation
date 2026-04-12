#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

int rank(char c) {
    if ('2' <= c && c <= '9') {
        return c - '2';
    }
    if (c == 'T') return 8;
    if (c == 'J') return 9;
    if (c == 'Q') return 10;
    if (c == 'K') return 11;
    if (c == 'A') return 12;
    assert(false); 
}

char trump;
int num[4][13];
char suit[4][13];

int main () {
    while (true) {
        cin >> trump;

        if (trump == '#') break;

        string token;
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 13; ++k) {
                cin >> token;
                num[j][k] = rank(token[0]);
                suit[j][k] = token[1];
            }
        }

        int ew_trick = 0, ns_trick = 0;
        int prev_winner = 3;

        for (int j = 0; j < 13; ++j) {
            int winner = -1;
            int max_rank = -1;
            bool trump_exists = false;
            for (int k = 0; k < 4; ++k) {
                if (trump == suit[k][j]) {
                    if (!trump_exists || num[k][j] > max_rank) {
                        max_rank = num[k][j];
                        winner = k;
                    }
                    trump_exists = true;
                } else if (!trump_exists && suit[prev_winner][j] == suit[k][j]) {
                    if (num[k][j] > max_rank) {
                        max_rank = num[k][j];
                        winner = k;
                    }
                }
            }

            if (winner % 2 == 0) {
                ++ns_trick;
            } else {
                ++ew_trick;
            }

            prev_winner = winner;
        }

        if (ew_trick > ns_trick) {
            cout << "EW " << (ew_trick - 6) << endl;
        } else {
            cout << "NS " << (ns_trick - 6) << endl;
        }
    }
    return 0;
}