#include <iostream>
#include <set>

using namespace std;
long long mods[200001];
int main() {
    long long N;
    long long X, M;
    cin >> N >> X >> M;

    int loop = 1;
    int loopbegin = -1;
    mods[0] = X;
    set<long long> st;
    st.insert(X);

    long long x = X;
    while (1) {
        x = (x * x) % M;
        if (st.find(x) != st.end()) {
            for (int i=0; i<loop; i++) {
                if (x == mods[i]) {
                    loopbegin = i;
                    break;
                }
            }
            break;
        }
        mods[loop++] = x;
        st.insert(x);
    }

    long long answer = 0;
    long long loopsum = 0;
    long long looplen = loop - loopbegin;
    for (int i=loopbegin; i<loop; i++) loopsum += mods[i];
    long long rest = N;
    for (int i=0; i<loopbegin; i++) {
        rest--;
        answer += mods[i];
    }

    answer += (rest / looplen) * loopsum;

    rest = rest % looplen;
    for (int i=0; i<rest; i++) {
        answer += mods[loopbegin+i];
    }
    cout << answer << endl;
    return 0;
}

