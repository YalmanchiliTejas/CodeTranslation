N = int(input())
A = list(map(int,input().split()))
mod = 10**9 + 7
ans = 0
X = sum(A)
for i in range(len(A)-1):
    Y = A[i]
    X -= Y
    ans += (Y * X)
print(ans % mod)