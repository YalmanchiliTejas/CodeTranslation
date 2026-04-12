#include<bits/stdc++.h>

using namespace std;

const int maxi=1e6+2;

int a[maxi];
string s;
vector<int> v[maxi];
map<int,int > mp;
int n;
int b[maxi];
int main()
{
    cin>>n;

    for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }

   sort(b+1,b+n+1);

   int left = b[n/2];
   int right = b[n/2+1];

   for (int i=1;i<=n;i++)
   {
       if (a[i]<=left) printf("%d\n",right); else printf("%d\n",left);
   }
    return 0;
}
//sala mala
