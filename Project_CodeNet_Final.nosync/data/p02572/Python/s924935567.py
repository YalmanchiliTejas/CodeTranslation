N = int(input())
a = list(map(int,input().split()))
#a = [100]*N
A = dict(zip(list(range(len(a))),a))
ans = 0
suma = 0
suma = sum(a)

for i in range(len(a)-1):
  suma -= A[i]
  ans = (ans + A[i]*suma)%1000000007
  
print(ans)