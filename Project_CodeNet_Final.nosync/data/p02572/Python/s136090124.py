N = int(input())
A = list(map(int,input().split()))
SumA = sum(A) - A[0]
ans = 0
mod = (10**9)+7
for i in range(N-1):
    ans += SumA * A[i]
    SumA -= A[i+1]
print(str(ans%mod))