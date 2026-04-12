#include <iostream>

using namespace std;

int N;
int *A;

int Rec(int left, int right, int n, int &ans)
{

  int rval = right, mid = (left + right)/2;

  if(left >= right)
  {
      if(A[left] >= n)
        ans = left;
    return rval;
  }


  if(n <= A[mid])
    rval = Rec(left, mid, n, ans);
  else if( A[mid] < n)
    rval = Rec(mid+1, right, n, ans);

  return rval;

}

int main()
{

  cin >> N;
  A = new int[N];

  for(int i = 0; i < N; ++i)
    cin >> A[i];

  int M; cin >> M;

  for(int i = 0; i < M; ++i)
  {
    int Num; cin >> Num;
    int ans = N;

    Rec(0, N, Num, ans);

    cout << ans << endl;

  }

  delete[] A;

  return 0;
}
