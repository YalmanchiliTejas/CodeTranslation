N = int(input())
A = list(map(int,input().split()))
total = 0
mod = 10**9+7
an = sum(A)

for i in range(N):
  total+=(an-A[i])*A[i]
s = total//2
print(s%mod)