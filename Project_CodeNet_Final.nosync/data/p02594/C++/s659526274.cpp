#include <bits/stdc++.h>
using namespace std;
typedef long long int l1;
typedef vector <int> vi;
typedef vector <long long int> v1;
#define pb push_back
#define mp make_pair
#define iter(i,a,b) for(i=a;i<b;i++)

l1 bin(v1 vec, l1 l, l1 r, l1 x)
{
    sort(vec.begin(),vec.end());
 	
    if (r >= l) { 
        l1 mid = l + (r - l) / 2; 
 		if (vec[mid] == x) 
            return mid;       
        if (vec[mid] > x) 
            return bin(vec, l, mid - 1, x);         
        return bin(vec, mid + 1, r, x); 
    } 
    return -1; 
    //index of first equal element returned;
    
}


int main()
{
    ios_base::sync_with_stdio(false);      //for fast cin and cout streams
    cin.tie(NULL);
    cout.tie(NULL);
    
    //THINK..THINK..THINK..nope..EVEN THOSE CORNER CASES
    //DONE ??..NO.!...GO BACK AGAIN NOW..dumbass
    //ALL RIGHT..GOOD TO GO..
    //MAKE IT SYNTACTICALLY CORRECT..though
    
    
    l1 n;
  cin>>n;
  if(n>=30)
    cout<<"Yes";
  else
    cout<<"No";
    
    

return 0;
}




