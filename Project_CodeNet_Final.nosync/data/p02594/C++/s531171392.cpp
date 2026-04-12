        #include<bits/stdc++.h>
        #define ll long long int
        #define vi vector<int>v
        #define vll vector<long long int>v
        #define vc vector<char>v
        #define vpi vector< pair <int,int> >v
        #define vpll vector< pair <long long int,long long int> >v
        #define pb v.push_back
        #define si set<int>s
        #define sc set<char>s
        #define nl cout<<endl
        //#define fl0 for(int i=0; i<n; i++)
        //#define fl1 for(int i=1; i<=n; i++)
        using namespace std;
        bool prime(int n)
        {
         for(int i=2; i<=(n/i); i++)
         {
             if(n%i==0){return 0;}
         }
         return 1;

        }

        int binarySearchCount(int arr[], int n, int t)
        {
            int left = 0;
            int right = n - 1;

            int count = 0;

            while (left <= right) {
                int mid = (right + left) / 2;

                if (arr[mid] <= t) {

                    count = mid + 1;
                    left = mid + 1;
                }

                else
                    right = mid - 1;
            }

            return count;

        }

        long long countGreater(long long arr[], int n, long long k)
    {
        long long l = 0;
        long long r = n - 1;
        long long leftGreater = n;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (arr[m] >= k) {
                leftGreater = m;
                r = m - 1;
            }

            else
                l = m + 1;
        }

        return (n - leftGreater);

    }
    bool tonmoy(char c)
    {
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
            return 0;
        return 1;
    }
    int main()
    {
      int n;
      cin>>n;
      if(n>=30){cout<<"Yes\n";}
      else {cout<<"No\n";}
    }
