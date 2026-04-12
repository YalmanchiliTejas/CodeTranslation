#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define ff first
#define ss second
#define fr(i,l,r) for (long long int i = l; i < r; ++i)
#define frr(i,l,r) for (long long int i = r; i >= l; --i) 
#define sortarr sort(arr,arr+n) //sorts array in asc order
#define sortarr_r sort(arr, arr+n, greater<long long int>()) //sorts array in desc order
#define make_set set<long long int>s //Set arranges in asc order
#define make_set_r set<long long int, greater <long long int>>s ////Set arranges in desc order
#define make_vector vector<long long int>v; 
#define max_heap priority_queue <int> pq; // max heap 
#define min_heap priority_queue <int, vector<int>, greater<int> > pq;  //min heap
#define make_pairVector vector<pair<long long int,long long int> > pairVector // vector of pairs
#define hashmap unordered_map<long long int, long long int>hashmap;
#define pb push_back

//transform(s.begin(), s.end(), s.begin(), ::tolower); //to convert a string entirely to lower case

//toupper(s[i]) or tolower(s[i]) // converting a character to upper or lower case

//map<pair<ll,ll>, ll > hash;          // pair,value hashmap where key is a pair
//hash[make_pair(i,j)] = 0;
//if(hash.find(make_pair(i,j)) == hash.end())


//map<ll,ll>::iterator itr;           // iterating a map
//for (itr = hash.begin();itr != hash.end(); itr++)
//{
//   itr->first = key  
//   itr->second = value
//}


// vector<string> v; //to convert vector to a set
// set<string> s(v.begin(), v.end());


// set<string>s;     // to convert set to a vector
// vector<string> v(s.begin(),s.end());


// cin >> x >> y;
// pairVector.pb(mp(x,y));


// string size = str.size()


// stack <int> s; 


// queue <int> gquiz; 


// __gcd(m, n) 

// ll arr[10e5 + 5];


// char arr[10e5 + 5];


//vec.insert(v.begin(),value)   -> to insert a value in the vector at the begin

// printf ("%.9f\n",x);
// cout << fixed << setprecision(9);

//covert integer to string :  to_string(integer)

// vector<vector<int> > ans( A , vector<int> (A, 0));  : to initialise a vector or vectors of size = A(total number of rows) and each row having A elements equal to 0




// void SieveOfEratosthenes(int n) 
// { 
//     // Create a boolean array "prime[0..n]" and initialize 
//     // all entries it as true. A value in prime[i] will 
//     // finally be false if i is Not a prime, else true. 
//     bool prime[n+1]; 
//     memset(prime, true, sizeof(prime)); 
  
//     for (int p=2; p*p<=n; p++) 
//     { 
//         // If prime[p] is not changed, then it is a prime 
//         if (prime[p] == true) 
//         { 
//             // Update all multiples of p greater than or  
//             // equal to the square of it 
//             // numbers which are multiple of p and are 
//             // less than p^2 are already been marked.  
//             for (int i=p*p; i<=n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
  
//     // Print all prime numbers 
//     for (int p=2; p<=n; p++) 
//        if (prime[p]) 
//           cout << p << " "; 
// } 




bool sortbysec(const pair<long long int,long long int> &a, const pair<long long int,long long int> &b) 
{ 
    return (a.second < b.second); 
}
bool compare(string &s1,string &s2) 
{ 
    return s1.size() < s2.size(); 
} 
int check_key(map<long long int, long long int> m, long long int key) 
{ 
    // Key is not present 
    if (m.find(key) == m.end()) 
        return 0; 
  
    return 1; 
} 

void yes()
{
    cout << "Yes" << endl;
}
void no()
{
    cout << "No" << endl;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // ll t;
    // cin >> t;
    // while(t--)
    // {
        ll n;
        cin >> n;
        if(n >= 30)
            yes();
        else
        {
            no();
        }
        
    // }
    return 0;
}   