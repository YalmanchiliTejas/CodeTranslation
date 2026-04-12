#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, tmp, count = 0;
    bool flag;
    vector<int> vec;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        flag = true;
        vec.push_back(tmp);
        for (int j = 0; j < i; j++) {
            if (vec[j] > tmp) {
                flag = false;
            }
        }
        if (flag == true) {
            count++;
        }
    }

    cout << count << endl;
   

    return 0;   
}