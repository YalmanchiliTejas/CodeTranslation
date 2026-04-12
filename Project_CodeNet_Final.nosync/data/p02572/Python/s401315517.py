N = int(input())
A = list(map(int, input().split()))
B = [A[0]]
ans = 0
m = 10 ** 9 + 7
for i in range(1, N):
    B.append(B[i - 1] + A[i])
    ans += A[i] * B[i - 1]
    ans %= m
print(ans)
    