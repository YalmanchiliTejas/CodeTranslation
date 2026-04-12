#include<iostream>
using namespace std;

int binary_search( int* a, int n , int v )
{
    int left = 0, right = n;

    if( a[n-1] < v )                            // 存在しない場合
        return n;

    while( left < right )
    {
        int mid = ( left + right ) / 2;
        if( a[mid] > v )
            right = mid;
        else if( a[mid] < v )
            left = mid + 1;                     // midではなくて、mid+1
        else
        {
            while( mid >= 0 && a[mid] == v )    //同じ数字が並んでいる場合、一番最初の要素を返す
                mid--;
            return mid + 1;
        }
    }

    if( a[left] < v )
        return left + 1;
    else
        return left;
}

int main()
{
    int n, q, v;

    cin >> n;

    int a[n];

    for( int i = 0; i < n; i++ )
        cin >> a[i];
    
    cin >> q;

    for( int i = 0; i < q; i++ )
    {
        cin >> v;
        cout << binary_search( a, n, v ) << endl;
    }

    return 0;
}
