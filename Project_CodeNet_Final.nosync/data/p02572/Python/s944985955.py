N = int(input())
A = list(map(int,input().split()))
mod = 1000000007
ans = 0
res = [A[0]]
for i in range(N-1):
    res.append(res[i]+A[i+1])
for i in range(1,N):
    ans = ans + (A[i]*res[i-1])%mod
ans = ans%mod
print(ans)