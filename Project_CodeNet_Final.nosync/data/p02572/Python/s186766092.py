N = int(input())
A = list(map(int, input().split()))

X = sum(A)
x = 0
ans = 0
for i in range(N):
    x += A[i]
    ans += A[i] * (X-x)

print(ans % ((10 ** 9) + 7))
