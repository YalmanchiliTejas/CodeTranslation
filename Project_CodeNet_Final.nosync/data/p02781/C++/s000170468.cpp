#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
#define rep(cnt,l) for(auto cnt=0;cnt<(l);++cnt)
#define repP(cnt,l) for(auto cnt=1;cnt<=(l);++cnt)

#define InputVector(A) while(cin >> A[idx]) idx++;
#define InputXVector(A, X) while(cin >> A[idx]) {idx++;if(idx==X) break;}
#define PrintVector(A) for(int i=0;i<A.size();i++) cout << A[i] << endl;
#define ErrorPrintVector(A) for(int i=0;i<A.size();i++) cerr << A[i] << endl;
template<class T>inline bool chmax(T& a, const T& b)noexcept { if (a < b) { a = b; return true; } return false; }
template<class T>inline bool chmin(T& a, const T& b)noexcept { if (a > b) { a = b; return true; } return false; }
using mat2d_t = std::vector<std::vector<long>>;

long gcd(long number1,long number2){
	long m = number1;
	long n = number2;

	if(number2 > number1){
		m = number2;
		n = number1;
	}

	long r = m % n;
    while(r!=0){
      m = n;
      n = r;
      r = m % n;
    }

	return n;
}

long lcm(long number1,long number2){
	return number1 * number2 / gcd(number1,number2);	
}


vector<string> split(const string &s, char delim) {
    vector<string> elems;
    string item;
    for (char ch: s) {
        if (ch == delim) {
            if (!item.empty())
                elems.push_back(item);
            item.clear();
        }
        else {
            item += ch;
        }
    }
    if (!item.empty())
        elems.push_back(item);
    return elems;
}

bool compare_by_b(tuple<int, string, int> a, tuple<int, string, int> b) {
    if(get<2>(a) != get<2>(b)){
        return get<2>(a) > get<2>(b);
    }
}

bool compare_by_string(tuple<int, string, int> a, tuple<int, string, int> b) {
    if(get<1>(a) != get<1>(b)){
        return get<1>(a) < get<1>(b);
    }else{
      	return get<2>(a) > get<2>(b);
    }
}

bool compare_by_b_of_pair(pair<long,long> a, pair<long,long> b) {
    if(a.first * b.second !=  b.first * a.second){
        return a.first *b.second < b.first * a.second;
    }
}

int check(vector<int> &v, int k, long weight)
{
  int i=0;
  for(int j=0;j<k;j++)
  {
    long tmp = 0;
    while(tmp + v[i] <= weight)
    {
      tmp += v[i];
      i++;
      if(i == v.size()) return v.size();
    }
  }
  return i;
}


long binary_search(vector<int> &v, int k)
{
	long left = 0;
  	long right = v.size() * 10000; //適宜書き換え
  	long mid;
  	while(right - left > 1)
    {
      	mid = (left + right) / 2;
      	int num = check(v,k,mid);
      	if(num >= v.size()) right = mid;
      	else left = mid;
    }
  	return right;
}

bool isComb(vector<int> &elem, int idx, int sum)
{
  if(sum == 0) return true;
  else if(idx >= elem.size() || sum < 0) return false;
  return isComb(elem, idx+1, sum) || isComb(elem, idx+1, sum - elem[idx]);
}

long Merge(vector<long> &v, int left, int mid, int right)
{
  long count = 0;
  int n_left = mid -left;
  int n_right = right -mid;
  vector<long> v_left(n_left);
  vector<long> v_right(n_right);
  for(int i=0;i<n_left;i++) v_left[i] = v[left+i];
  for(int i=0;i<n_right;i++) v_right[i] = v[mid+i];
  int i=0,j=0;
  for(int k=left;k<right;k++)
  {
    //count++;
    if(i < n_left && j < n_right && v_left[i] <= v_right[j] || i < n_left && j >= n_right)
    {
      v[k] = v_left[i];
      i++;
    }
    else if(i < n_left && j < n_right && v_left[i] > v_right[j] || i >= n_left && j < n_right)
    {
      v[k] = v_right[j];
      j++;
      count += n_left-i;
    }
  }
  return count;
}

long MergeSort(vector<long> &v, int left, int right)
{
  long count = 0;
  if(left + 1 < right)
  {
    int mid = (left + right) / 2;
    count += MergeSort(v, left, mid);
    count += MergeSort(v, mid, right);
    count += Merge(v, left, mid, right);
  }
  return count;
}

int Partition(vector<tuple<int, string, long>> &v, int p, int r)
{
  int x = get<2>(v[r]);
  int i = p-1;
  tuple<int, string, long> tmp;
  for(int j=p;j<r;j++)
  {
    if(get<2>(v[j]) <= x)
    {
      i++;
      tmp = v[j];
      v[j] = v[i];
      v[i] = tmp;
    }
  }
  tmp = v[r];
  v[r] = v[i+1];
  v[i+1] = tmp;
  return i+1;
}

void QuickSort(vector<tuple<int, string, long>> &v, int p, int r)
{
  if(p < r)
  {
    int q = Partition(v, p, r);
    QuickSort(v, p, q-1);
    QuickSort(v, q+1, r);
  }
}

void CountingSort(vector<int> &a, vector<int> &b, int k)
{
  vector<int> c(k+1);
  for(int i=0;i<a.size();i++) c[a[i]]++;
  for(int i=1;i<=k;i++) c[i] +=c[i-1];
  for(int i=a.size()-1;i>=0;i--)
  {
    if(c[a[i]] > 0)
    {
      b[c[a[i]]-1] = a[i];
      c[a[i]]--;
    }
  }
}

int BubbleSort(vector<long> &v)
{
  int cnt=0;
  int tmp;
  for(int i=0;i<v.size();i++)
  {
    for(int j=v.size()-1;j>i;j--)
    {
      if(v[j] < v[j-1])
      {
        tmp=v[j];
        v[j]=v[j-1];
        v[j-1]=tmp;
        cnt++;
      }
    }
  }
  return cnt;
}

struct Node
{
  int id;
  int parentId;
  int sibling;
  int degree;
  int depth;
  int height;
  string type;
  vector<int> childNodes; 
};

#define Space "_"

void PrintPreOrder(vector<Node> nodes, Node n)
{
  cout << n.id;
  for(int i=0;i<n.childNodes.size();i++)
  {
    if(n.childNodes[i] == -1) continue;
    cout << Space;
    PrintPreOrder(nodes, nodes[n.childNodes[i]]);
  }
}

void PrintInOrder(vector<Node> nodes, Node n)
{
  if(n.childNodes.size() == 0) return;
  if(n.childNodes[0] != -1) PrintInOrder(nodes, nodes[n.childNodes[0]]);
  cout << Space << n.id;
  if(n.childNodes[1] != -1) PrintInOrder(nodes, nodes[n.childNodes[1]]);
}

void PrintPostOrder(vector<Node> nodes, Node n)
{
  for(int i=0;i<n.childNodes.size();i++)
  {
    if(n.childNodes[i] == -1) continue;
    PrintPostOrder(nodes, nodes[n.childNodes[i]]);
    cout << Space;
  }
  cout << n.id;
}

int setDepth(vector<Node>& n, vector<int> cn, int depth)
{
  	int height=0;
  	for(int i=0;i<cn.size();i++)
    {
      	n[cn[i]].depth = depth + 1;
      	n[cn[i]].height = setDepth(n, n[cn[i]].childNodes, n[cn[i]].depth);
      	if(height < n[cn[i]].height) height = n[cn[i]].height;
      	
    }
  	if(cn.size() == 0 || (cn[0] == -1 && cn[1] == -1)) return 0;
  	else return height+1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    const long div = 1000000007;
    string N;
  	long K;
  	cin >> N >> K;
  	long idx = 0;
  	int l = N.size();
  	mat2d_t dp0 = mat2d_t(l, vector<long>(4, 0)); // smaller
    mat2d_t dp1 = mat2d_t(l, vector<long>(4, 0)); // smaller?
  	
	dp0[0][0] = 1;
  	rep(i,l)
    {
        N[i] -='0';
        if (i == 0) {
            dp0[0][1] = N[i]-1;
            dp1[0][1] = 1;
            continue;
        }
        dp0[i][0] = 1;
      	//０じゃない桁の数
        repP(j, K)
        {
            dp0[i][j] += dp0[i-1][j-1] * 9;
            dp0[i][j] += dp0[i-1][j];
 
            if (N[i]) {
              	cerr << dp1[i-1][j] << ":" << dp1[i-1][j-1] << ":" <<  (N[i]-1) << endl;
                dp0[i][j] += dp1[i-1][j];
                dp0[i][j] += dp1[i-1][j-1] * (N[i]-1);
                dp1[i][j] += dp1[i-1][j-1];
            } else {
                dp1[i][j] = dp1[i-1][j];
            }
          	
        }
    }
  	rep(i,l)
    {
      repP(j,K)
      {
      	cerr << dp0[i][j] << " ";
      }
      cerr << endl;
    }
  
  	rep(i,l)
    {
      repP(j,K)
      {
      	cerr << dp1[i][j] << " ";
      }
      cerr << endl;
    }
  	
 
    cout << dp0[l-1][K] + dp1[l-1][K] << endl;
 
  	return 0;
}
