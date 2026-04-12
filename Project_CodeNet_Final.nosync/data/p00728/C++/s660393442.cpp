#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define pb push_back

int main()
{
    int n,j=0;
    vector<int> x(20);

    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        int score;
        int sum = 0, max = 0, min = 1000;
        for (int i = 0;i<n;i++)
        {
            cin >> score;
            if(max <  score){
                max = score;
            }
            if(min > score){
                min = score;
            }
            sum += score;
        }
        sum = sum - max - min;
        // cout << sum <<  " max:" << max << " min:" << min << endl;
        x[j] = sum/(n-2);
        j++; 
    }
    for(int i=0;i<j;i++){
        cout << x[i] << endl;
    }
}

