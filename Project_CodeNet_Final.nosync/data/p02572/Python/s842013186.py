mod = 10**9 + 7
n = int(input())
A = list(map(int,input().split()))
S = sum(A)%mod
ans = 0
for a in A:
    ans += a * (S - a)
print(ans*pow(2,-1,mod)%mod)
