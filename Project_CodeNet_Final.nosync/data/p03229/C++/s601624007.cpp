#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    B = A;

    int left = A[0];
    int right = A[0];
    long long smallAns = 0;
    int diff;
    A.erase(A.begin() + 0);
    for (int i = 1; i < N; i++)
    {
        diff = max({abs(left - A[0]), abs(right - A[0]), abs(left - A[A.size() - 1]), abs(right - A[A.size() - 1])});
        smallAns += diff;
        if (diff == abs(left - A[0]))
        {
            left = A[0];
            A.erase(A.begin() + 0);
        }
        else if (diff == abs(right - A[0]))
        {
            right = A[0];
            A.erase(A.begin() + 0);
        }
        else if (diff == abs(left - A[A.size() - 1]))
        {
            left = A[A.size() - 1];
            A.erase(A.begin() + A.size() - 1);
        }
        else if (diff == abs(right - A[A.size() - 1]))
        {
            right = A[A.size() - 1];
            A.erase(A.begin() + A.size() - 1);
        }
    }

    left = B[B.size() - 1];
    right = B[B.size() - 1];
    long long largeAns = 0;
    B.erase(B.begin() + B.size() - 1);
    for (int i = 1; i < N; i++)
    {
        diff = max({abs(left - B[0]), abs(right - B[0]), abs(left - B[B.size() - 1]), abs(right - B[B.size() - 1])});
        largeAns += diff;
        if (diff == abs(left - B[0]))
        {
            left = B[0];
            B.erase(B.begin() + 0);
        }
        else if (diff == abs(right - B[0]))
        {
            right = B[0];
            B.erase(B.begin() + 0);
        }
        else if (diff == abs(left - B[B.size() - 1]))
        {
            left = B[B.size() - 1];
            B.erase(B.begin() + B.size() - 1);
        }
        else if (diff == abs(right - B[B.size() - 1]))
        {
            right = B[B.size() - 1];
            B.erase(B.begin() + B.size() - 1);
        }
    }

    if (smallAns > largeAns)
    {
        cout << smallAns << endl;
    }
    else
    {
        cout << largeAns << endl;
    }
}