#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    vector<int> A;

    cin >> N;
    A = vector<int>(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    long long int sum = 0;
    vector<int> M;
    
    M.push_back(A[0]);
    A.erase(A.begin());
    
    while (!A.empty()){
        int max;
        int insert_p = 0;
        int insert_v = 0;
        
        max = abs(A[0] - M[0]);

        if (abs(A.back() - M[0]) > max){
            max = abs(A.back() - M[0]);
            insert_p = 0;
            insert_v = 1;
        }

        if (abs(A[0] - M.back()) > max){
            max = abs(A[0] - M.back());
            insert_p = 1;
            insert_v = 0;
        }

        if (abs(A.back() - M.back()) > max){
            max = abs(A.back() - M.back());
            insert_p = 1;
            insert_v = 1;
        }

        int v;
        if (insert_v == 0){
            v = A[0];
            A.erase(A.begin());
        } else {
            v = A.back();
            A.pop_back();
        }

        if (insert_p == 0){
            M.insert(M.begin(), v);
        } else M.push_back(v);

        sum += max;
    }

    cout << sum << endl;

    return 0;
}

