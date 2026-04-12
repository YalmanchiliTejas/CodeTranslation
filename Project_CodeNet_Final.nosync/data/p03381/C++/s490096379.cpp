# include<iostream>
# include<cstdio>
# include<algorithm>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    int a[200003];
    int b[200003];
    int n;
    while(cin >> n && n!=0)
    {
        int i;
        for(i = 1; i <= n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a+1, a+n+1);
        int mid = (1+n)/2;
        //cout << mid << endl;
        //for(i = 1; i <= n; ++i)
        //cout << a[i] << " ";
        //cout << endl;
        for(i = 1; i <= n; ++i)
        {
            if(b[i] > a[mid])
                cout << a[mid] << endl;
            else if(b[i] < a[mid])
                cout << a[mid+1] << endl;
            else
                cout << a[mid+1] << endl;
        }
    }
    return 0;
}
