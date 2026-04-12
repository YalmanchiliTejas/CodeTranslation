n = int(input())
A = list(map(int,input().split()))
L = [0]*(n+1)
ans = 0
for i in range(n):
  L[i+1] = L[i]+A[i]
for i in range(1,n):
  ans += L[i]*A[i]
print(ans % (10**9+7))