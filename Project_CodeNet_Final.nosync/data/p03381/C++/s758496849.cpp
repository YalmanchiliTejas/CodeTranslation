#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[200005], A2[200005];
void Read()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i], A2[i] = A[i];
    sort(A2 + 1, A2 + N + 1);
}
int main()
{
    Read();
    for(int i = 1; i <= N; i++)
    {
        if(A[i] >= A2[N / 2 + 1])
            cout << A2[N / 2] << "\n";
        else
            cout << A2[N / 2 + 1] << "\n";
    }
    return 0;
}
