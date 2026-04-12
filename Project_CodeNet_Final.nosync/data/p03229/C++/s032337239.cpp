#include <iostream>
#include <queue>
using namespace std;

long A[100000];

int main()
{
    long N;
    cin >> N;

    priority_queue<long> A_;
    for(int n = 0; n < N; n++) {
        long m;
        cin >> m;
        A_.push(m);
    }
    long i = N - 1;
    while (!A_.empty()) {
        A[i] = A_.top();
        A_.pop();
        i--;
    }

    /*
    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }*/
    
    long l = 0;
    long r = N - 1;
    long sum = 0;

    long c = A[N / 2]; // N が偶数の場合はスタートは真ん中のどっちでも良い（右が選ばれる）
    long d = 0; // 0 が左、1 が右

    if(N >= 3 && N % 2 != 0) {
        //cout << A[N / 2] << endl;
        //cout << A[N / 2 - 1];
        //cout << A[N / 2 + 1];
        if(abs(A[N / 2] - A[N / 2 - 1]) < abs(A[N / 2 + 1] - A[N / 2])) {
            d = 1;
            //cout << "d = 1" << endl;
        }
        // なお、N が偶数の場合は遠い方に左に飛ぶので d = 0 でよい
    }
    while(l != r) {
        if(d == 0) {
            //cout << d << ": l = " << l << ", " << abs(c - A[l]) << endl;
            sum += abs(c - A[l]);
            c = A[l];
            l++;
        } else {
            //cout << d << ": r = " << r << ", " << abs(c - A[r]) << endl;
            sum += abs(c - A[r]);
            c = A[r];
            r--;
        }
        //cout << sum << endl;
        d = 1 - d;
    }
    cout << sum;

    return 0;
}
