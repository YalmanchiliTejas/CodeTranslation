N = int(input())
A = list(map(int,input().split()))
P = 0
S = sum(A)
m = 10**9+7

for i in range(N):
  S -= A[i]
  P += A[i]*S
  
ans = P%m
print(ans)