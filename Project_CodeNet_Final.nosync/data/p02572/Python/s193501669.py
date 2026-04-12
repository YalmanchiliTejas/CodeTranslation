N=int(input())
List = list(map(int, input().split()))
midList = [0]*(N-1)
mid = 0
for i in range(N-2,-1,-1):
  mid += List[i+1]
  midList[i] = mid
res=0
for i in range(N-1):
  a = List[i] % 1000000007
  b =  midList[i] % 1000000007
  res += a*b
print(res%1000000007)