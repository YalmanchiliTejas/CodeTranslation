#include "bits/stdc++.h"

using namespace std;

int isSheepFn(bool prevTest, int prevIsSheep, int prevprevIsSheep) {
    int ret = 0;
    if (prevIsSheep == 1 && prevTest) {
        if (prevprevIsSheep == 1) {
            ret = 1;
        }
        else {
            ret = -1;
        }
    }
    else if (prevIsSheep == 1 && !prevTest) {
        if (prevprevIsSheep == 1) {
            ret = -1;
        }
        else {
            ret = 1;
        }
    }
    else if (prevIsSheep == -1 && prevTest) {
        if (prevprevIsSheep == 1) {
            ret = -1;
        }
        else {
            ret = 1;
        }
    }
    else { // prevIsSheep == -1 && !prevTest
        if (prevprevIsSheep == 1) {
            ret = 1;
        }
        else {
            ret = -1;
        }
    }
    return ret;
}

bool check(vector<int>& isSheep, const vector<bool>& testemonies) {
    int N = testemonies.size();
    for (int i = 2; i < N; ++i) {
        isSheep[i] = isSheepFn(testemonies[i - 1], isSheep[i - 1], isSheep[i - 2]);
    }

    bool ret = false;
    if (isSheepFn(testemonies[N - 1], isSheep[N - 1], isSheep[N - 2]) == isSheep[0]
            && isSheepFn(testemonies[0], isSheep[0], isSheep[N - 1]) == isSheep[1]) {
        ret = true;
    }
    return ret;
}

void serializeAndOut(const vector<int>& isSheep) {
    for (int i = 0; i < isSheep.size(); ++i) {
        cout << (isSheep[i] == 1 ? "S" : "W");
    }
    cout << endl;
}

void Main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    vector<bool> testemonies(N, true);
    for (int i = 0; i < N; ++i) {
        testemonies[i] = (s[i] == 'o');
    }

    vector<int> isSheep(N, 0);
    // SS...
    isSheep[0] = 1;
    isSheep[1] = 1;
    if (check(isSheep, testemonies)) {
        serializeAndOut(isSheep);
        return;
    }

    // SW...
    isSheep[0] = 1;
    isSheep[1] = -1;
    if (check(isSheep, testemonies)) {
        serializeAndOut(isSheep);
        return;
    }

    // WS...
    isSheep[0] = -1;
    isSheep[1] = 1;
    if (check(isSheep, testemonies)) {
        serializeAndOut(isSheep);
        return;
    }

    // WW...
    isSheep[0] = -1;
    isSheep[1] = -1;
    if (check(isSheep, testemonies)) {
        serializeAndOut(isSheep);
        return;
    }

    cout << -1 << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
