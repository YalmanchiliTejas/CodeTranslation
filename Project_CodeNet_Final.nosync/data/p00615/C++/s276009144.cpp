#include <iostream>
using namespace std;

int* marge(int* array1, int length1, int* array2, int length2)
{
  int length_new = length1 + length2;
  int* array_new = new int[length_new];
  for (int i=0, j=0, k=0; k<length_new; k++)
  {
    if (i < length1 && j < length2)
    {
      if (array1[i] < array2[j])
      {
        array_new[k] = array1[i];
        i++;
      }
      else
      {
        array_new[k] = array2[j];
        j++;
      }
    }
    else if ( i >= length1 )
    {
      array_new[k] = array2[j];
      j++;
    }
    else
    {
      array_new[k] = array1[i];
      i++;
    }
  }
  return array_new;
}

int max_diff(int* array, int length)
{
  int max = array[0];
  for (int i = 1; i < length; i++)
  {
    int diff = array[i] - array[i-1];
    if (max < diff)
    {
      max = diff;
    }
  }
  return max;
}

int main(void)
{
  int n, m;
  while (true)
  {
    cin >> n >> m;
    if ( n == 0 && m == 0 ) break;
    
    int* up_line = new int[n];
    for (int i = 0; i < n; i++)
    {
      cin >> up_line[i];
    }

    int* down_line = new int[m];
    for (int j = 0; j < m; j++)
    {
      cin >> down_line[j];
    }

    int* marge_line = marge(up_line, n, down_line, m);

    delete[] up_line;
    delete[] down_line;

    int max = max_diff(marge_line, n+m);

    cout << max << endl;

    delete[] marge_line;
  }
  return 0;
}