  #include <iostream>

    #include <bits/stdc++.h>
    #include<string>
    #include<string.h>
    #define ll long long
    #define ll long long
    #define ld long double
    #define ctoi(x) x-'0'
    #define pshb(a) cin >> x;a.push_back(x)
    #define fr(i,n) for(ll i=0;i<n;i++)
    #define alph "abcdefghijklmnopqrstuvwxyz"
    #define alph1 "abcdefghijklmnopqrstuvwxyz"
    #include <vector>#include <bits/stdc++.h>
    #include<string>
    #include<string.h>
    #define ll long long
    #define ll long long
    #define ld long double
    #define ctoi(x) x-'0'
    #define pb(x) cin>>x; a.push_back(x)
    #define srt() sort(a.begin(),a.end())
    #define fr(i,n) for(ll i=0;i<n;i++)
    #define alph "abcdefghijklmnopqrstuvwxyz"
    #define alph1 "abcdefghijklmnopqrstuvwxyz"
    #include <vector>
    #include<math.h>
    #define WUBBAxxLUBAxxDUBxxDUB int main
    #define salamo3lekooooom ios::sync_with_stdio(false)
    using namespace std;
    bool sortbysec(const pair<int,int> &a,
                   const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    #define LIMIT 1000000
    long long i, j;
    long long prime_flag[LIMIT];
    void calculate_prime_flag()
    {
        prime_flag[0] = prime_flag[1] = 1;
        for(i=2; i<LIMIT; i++)
        {
            if (prime_flag[i]==0)
            {
                for(j=i*i; j<LIMIT; j+=i)
                {
                    prime_flag[j] = 1;
                }
            }
        }
    }




    int LPS(char *str)
    {
        int n=strlen(str);
        int i,j,cl;
        int l[n][n];
        for(i=0; i<n; i++)
            l[i][i]=1;
        for(cl=2; cl<=n; cl++)
        {
            for(i=0; i<n-cl+1; i++)
            {
                j=i+cl-1;
                if(str[i]==str[j]&&cl==2)
                    l[i][j]=2;
                else if (str[i]==str[j])
                    l[i][j]=l[i+1][j-1]+2;
                else
                    l[i][j]=max(l[i][j-1],l[i+1][j]);


            }
        }
        return l[0][n-1];


    }
    int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }


    int findGCD(int arr[], int n)
    {
        int result = arr[0];
        for (int i = 1; i < n; i++)
            result = gcd(arr[i], result);

        return result;
    }



bool prime(int s)
{
    for(int i=2; i<= sqrt(s); i++)
    {
        if ((s%i) != 0)
            return true;
        else
            return false;
    }
}
int myXOR(int x, int y)
{
    int res = 0; // Initialize result

    // Assuming 32-bit Integer
    for (int i = 31; i >= 0; i--)
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}
/////3aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
  // Get SHWIFTY
 void SieveOfEratosthenes(int z,int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it
            // numbers which are multiple of p and are
            // less than p^2 are already been marked.
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=z; p<=n; p++)
       if (prime[p])
          cout << p << " ";
}

    WUBBAxxLUBAxxDUBxxDUB()
    {
        salamo3lekooooom;


    ll n,m;
    cin>>n>>m;
    if(m==n)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;


           return 0;
    }
