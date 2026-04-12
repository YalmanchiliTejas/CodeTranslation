N = int(input())
A = list(map(int, input().split()))
B = [0] * N
B[0] = A[0]
for i in range(1, N):
    B[i] = B[i - 1] + A[i]
ans = 0
for i in range(N):
    ans += (A[i] * (B[-1] - B[i]))
print(ans % (10 ** 9 + 7))
