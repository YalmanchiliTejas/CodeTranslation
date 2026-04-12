#include<bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int arr1[100005];
int arr2[100005];
long long res1, res2;

long long calcSum1()
{
    long long ret = 0;
    for(int i = 0; i + 1< n; i++)
        ret += abs(arr1[i + 1] - arr1[i]);
    return ret;
}

long long calcSum2()
{
    long long ret = 0;
    for(int i = 0; i + 1< n; i++)
        ret += abs(arr2[i + 1] - arr2[i]);
    return ret;
}

int main()
{
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        if(n % 2 == 1)
        {
            int l, r, indL, indR;
            arr1[n / 2] = arr[0];
            l = n / 2 - 1, r = n / 2 + 1;
            indL = 1, indR = n - 1;
            while(l >= 0)
            {
                if((n / 2 - l) % 2 == 1)
                {
                    arr1[l] = arr[indR];
                    arr1[r] = arr[indR - 1];
                    indR -= 2;
                }
                else
                {
                    arr1[l] = arr[indL];
                    arr1[r] = arr[indL + 1];
                    indL += 2;
                }
                l--, r++;
            }

            res1 = calcSum1();

            arr2[n / 2] = arr[n - 1];
            l = n / 2 - 1, r = n / 2 + 1;
            indL = 0, indR = n - 2;
            while(l >= 0)
            {
                if((n / 2 - l) % 2 == 0)
                {
                    arr2[l] = arr[indR];
                    arr2[r] = arr[indR - 1];
                    indR -= 2;
                }
                else
                {
                    arr2[l] = arr[indL];
                    arr2[r] = arr[indL + 1];
                    indL += 2;
                }
                l--, r++;
            }
            res2 = calcSum2();
            cout << max(res1, res2) << endl;
        }
        else
        {
            int l, r, indL, indR;
            arr1[n / 2] = arr[0];
            l = n / 2 - 1, r = n / 2 + 1;
            indL = 1, indR = n - 1;
            while(l >= 0 || r < n)
            {
                if((n / 2 - l) % 2 == 1)
                {
                    arr1[l] = arr[indR];
                    if(indR)
                    arr1[r] = arr[indR - 1];
                    indR -= 2;
                }
                else
                {
                    arr1[l] = arr[indL];
                    if(indL + 1 < n)
                        arr1[r] = arr[indL + 1];
                    indL += 2;
                }
                l--, r++;
            }

            res1 = calcSum1();

            arr1[n / 2 - 1] = arr[0];
            l = n / 2 - 2, r = n / 2;
            indL = 1, indR = n - 1;
            while(l >= 0 || r < n)
            {
                if((n / 2 - l) % 2 == 1)
                {
                    arr1[l] = arr[indR];
                    if(indR)
                        arr1[r] = arr[indR - 1];
                    indR -= 2;
                }
                else
                {
                    arr1[l] = arr[indL];
                    if(indL + 1 < n)
                        arr1[r] = arr[indL + 1];
                    indL += 2;
                }
                l--, r++;
            }

            res1 = max(res1, calcSum1());

            arr2[n / 2] = arr[n - 1];
            l = n / 2 - 1, r = n / 2 + 1;
            indL = 0, indR = n - 2;
            while(l >= 0 || r < n)
            {
                if((n / 2 - l) % 2 == 0)
                {
                    arr2[l] = arr[indR];
                    if(indR)
                    arr2[r] = arr[indR - 1];
                    indR -= 2;
                }
                else
                {
                    arr2[l] = arr[indL];
                    if(indL + 1 < n)
                    arr2[r] = arr[indL + 1];
                    indL += 2;
                }
                l--, r++;
            }
            res2 = calcSum2();

            arr2[n / 2 - 1] = arr[n - 1];
            l = n / 2 - 2, r = n / 2;
            indL = 0, indR = n - 2;
            while(l >= 0 || r < n)
            {
                if((n / 2 - l) % 2 == 0)
                {
                    arr2[l] = arr[indR];
                    if(indR)
                    arr2[r] = arr[indR - 1];
                    indR -= 2;
                }
                else
                {
                    arr2[l] = arr[indL];
                    if(indL + 1 < n)
                        arr2[r] = arr[indL + 1];
                    indL += 2;
                }
                l--, r++;
            }
            res2 = max(res2, calcSum2());
            cout << max(res1, res2) << endl;
        }
    }

    return 0;
}
