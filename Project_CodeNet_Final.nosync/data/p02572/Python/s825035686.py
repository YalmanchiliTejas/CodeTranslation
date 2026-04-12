mod =10**9+7
n = int(input())
A = list(map(int,input().split()))

ans = 0
sum_a = sum(A)
for a in A:
  ans = (ans + (sum_a - a)*a)%mod

ans = (ans*pow(2,mod-2,mod))% mod
print(ans) 