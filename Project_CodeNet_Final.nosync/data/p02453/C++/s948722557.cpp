#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;

int main()
{
    int n, temp;
    scanf("%d", &n);

    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        vec.push_back(temp);
    }

    int q, num;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &num);
        vector<int>::iterator itr = lower_bound(vec.begin(), vec.end(), num);
        printf("%d\n", itr - vec.begin());
    }


    return 0;
}

