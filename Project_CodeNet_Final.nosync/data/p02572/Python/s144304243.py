N = int(input())
A = list(map(int,input().split()))

sum = sum(A)
ans = 0
M = 10**9 + 7

for i in range(N):
    ans += (A[i] * (sum - A[i]))
    ans %= M

ans = (ans * pow(2,M-2,M)) % M
print(ans)
