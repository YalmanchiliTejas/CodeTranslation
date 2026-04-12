N = int(input())
A = list(map(int, input().split()))

X = 0
Ans = 0

for i in range(N - 1):
    X += A[i]
    Ans += X * A[i + 1]
    Ans = Ans % (10 ** 9 + 7)

print(Ans)
