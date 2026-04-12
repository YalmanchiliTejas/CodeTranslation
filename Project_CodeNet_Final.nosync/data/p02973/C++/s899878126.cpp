#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long int;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<priority_queue<int>> q(n);
    int index = 0;
    q[0].push(a[0]);
    for(int i = 1; i < n; i++)
    {
        if(a[i] <= a[i - 1]){
            for(int j = index + 1; j < n; j++)
            {
                if(q[j].empty())
                {
                    q[j].push(a[i]);
                    index = j;
                    break;
                }else if(q[j].top() < a[i])
                {
                    q[j].push(a[i]);
                    index =  j;
                    break;
                }
            }
        }else{
            for(int j = 0; j <= index; j++)
            {
                if(q[j].empty())
                {
                    q[j].push(a[i]);
                    index = j;
                    break;
                }else if(q[j].top() < a[i])
                {
                    q[j].push(a[i]);
                    index = j;
                    break;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(q[i].size() != 0) count++;
    }
    cout << count << endl;
}