#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<utility>
using namespace std;
#define ll long long;
long long mod=1000000007;





bool isPrime(long long n)
{

    if (n <= 1)
        return false;


    for (long long i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}






bool isPalindrome(string s)
{

    int l = 0;
    int h = s.size()-1;


    while (h > l)
    {
        if (s[l++] != s[h--])
        {

            return false;
        }
    }
   return true;
}







int ternarySearch(int l, int r, int key, int ar[])

{
    while (r >= l) {

        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }

        // Since key is not present at mid,
        // check in which region it is present
        // then repeat the Search operation
        // in that region

        if (key < ar[mid1]) {

            // The key lies in between l and mid1
            r = mid1 - 1;
        }
        else if (key > ar[mid2]) {

            // The key lies in between mid2 and r
            l = mid2 + 1;
        }
        else {

            // The key lies in between mid1 and mid2
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    // Key not found
    return -1;
}






  int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was
    // not present
    return -1;
}





int main(){
ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
int x;
cin>>x;
if(x>=30){
   cout<<"Yes"<<endl;
}else{
   cout<<"No"<<endl;
}
 return 0;   
}