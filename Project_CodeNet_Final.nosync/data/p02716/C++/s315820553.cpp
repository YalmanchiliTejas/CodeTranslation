#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int64_t> A(N);
    for (auto & x : A)
        cin >> x;

    vector<int64_t> dp1(N);
    vector<int64_t> dp2(N);
    dp1[0] = 0;
    dp1[1] = max(A[0], A[1]);
    dp2[0] = A[0];
    dp2[1] = max(A[0], A[1]);
    for (int i = 2; i < N; ++i)
    {
        dp2[i] = max(A[i] + dp2[i - 2], (i % 2) ? dp2[i-1] : (A[i] + dp2[i - 2]));
        dp1[i] = max(A[i] + dp1[i - 2], dp2[i-1]);
    }

    cout << dp1[N-1] << endl;

    /*if (N % 2 == 0)
    {
        int64_t odds = 0;
        int64_t evens = 0;

        for (int i = 0; i < N; i += 2)
        {
            odds += A[i];
        }

        for (int i = 1; i < N; i += 2)
        {
            evens += A[i];
        }

        cout << ((odds > evens) ? odds : evens) << endl;
    }
    else
    {
        int64_t median = A[N / 2];
        int64_t withMedian;
        int64_t withoutMedian;

        int64_t oddsBefore = 0;
        int64_t oddsAfter = 0;
        int64_t evensBefore = 0;
        int64_t evensAfter = 0;
        for (int i = 0; i < (N / 2) - 1; i++)
        {
            if (i % 2 == 0)
                oddsBefore += A[i];
            else
                evensBefore += A[i];
        }

        for (int i = (N / 2) + 2; i < A.size(); i++)
        {
            int j = i - (N / 2) + 2;
            if (j % 2 == 0)
                oddsAfter += A[i];
            else
                evensAfter += A[i];
        }

        withMedian = median + max(oddsBefore, evensBefore) + max(oddsAfter, evensAfter);

        oddsBefore = 0;
        oddsAfter = 0;
        evensBefore = 0;
        evensAfter = 0;
        for (int i = 0; i < (N / 2); i++)
        {
            if (i % 2 == 0)
                oddsBefore += A[i];
            else
                evensBefore += A[i];
        }
        for (int i = (N / 2) + 1; i < A.size(); i++)
        {
            int j = i - (N / 2) + 1;
            if (j % 2 == 0)
                oddsAfter += A[i];
            else
                evensAfter += A[i];
        }

        withoutMedian =  max(oddsBefore, evensBefore) + max(oddsAfter, evensAfter);

        cout << ((withMedian > withoutMedian) ? withMedian : withoutMedian) << endl;
    }*/

    return 0;
}
