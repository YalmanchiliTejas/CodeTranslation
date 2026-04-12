#include <iostream>
#include <algorithm>

using namespace std;

long long init;
int year;

long long tanri(double r, long long t) {
    long long A = init;
    long long sum = 0;
    for (int i = 0; i < year; i++) {
        sum += A * r;
        A -= t;
    }
    return sum + A;
}

long long hukuri(double r, long long t) {
    long long A = init;
    
    for (int i = 0; i < year; i++) {
        A = A + A * r - t;
    }
    return A;
}

int main()
{
    int m;

    cin >> m;
    while (m--) {
        long long ans = 0;
        int n;

        cin >> init >> year >> n;
        while (n--) {
            int type;
            long long tesu;
            double ritu;

            cin >> type >> ritu >> tesu;
            if (type == 0) 
                ans = max(ans, tanri(ritu, tesu));
            else if (type == 1)
                ans = max(ans, hukuri(ritu, tesu));
        }
        cout << ans << endl;
    }

    return 0;
}