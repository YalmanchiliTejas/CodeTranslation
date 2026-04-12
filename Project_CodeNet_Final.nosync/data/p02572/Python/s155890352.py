n = int(input())
A = list(map(int, input().split()))
M = 10 ** 9 + 7
ans = 0
B = [A[0]]
for j in range(1,n):
    B.append(A[j]+B[j-1])
for i in range(n-1):
    ans += A[i] * (B[-1]-B[i])
    ans %= M
ans %= M
print(ans)