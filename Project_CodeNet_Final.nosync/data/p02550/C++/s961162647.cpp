#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t N, X, M;
    cin >> N >> X >> M;

    vector<size_t> flag(M, 0);
    vector<size_t> seq;

    seq.reserve(M);
    size_t pri_X = X;
    size_t n1 = 1;
    size_t n2 = N;
    for (size_t n = 1; n <= N; ++n)
    {
        size_t A = (n == 1) ? X : (pri_X * pri_X) % M;

        if (flag[A] > 0)
        {
            n1 = flag[A];
            n2 = n;
            break;
        }

        seq.push_back(A);
        flag[A] = n;
        pri_X = A;
    }

    vector<size_t> head, roop, tail;

    head.assign(seq.begin(), seq.begin() + (n1 - 1));
    roop.assign(seq.begin() + (n1 - 1), seq.end());
    size_t hlen = head.size();
    size_t rlen = roop.size();

    size_t num  = (N - hlen) / rlen;
    size_t rest = N - hlen - rlen * num;

    size_t out = 0;
    for (size_t i = 0; i < roop.size(); ++i) { out += roop[i]; };

    out *= num;
    for (size_t i = 0; i < head.size(); ++i) { out += head[i]; };
    for (size_t i = 0; i < rest; ++i) { out += roop[i]; };


    cout << out << endl;


    return 0;
}
