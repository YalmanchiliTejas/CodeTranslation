N = int(input())
A = list(map(int,input().split()))
mod = 1000000007
s = 0
S = sum(A)
for i in range(N - 1):
  S -= A[i]
  s += (A[i]*(S))%mod
print(s%mod)    