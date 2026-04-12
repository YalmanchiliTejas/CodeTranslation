A, B, C, X, Y = [int(x) for x in input().split()]
ans = 10 ** 10
C *= 2
for i in range(1 + 10 ** 5):
    cnt = C * i
    cnt += A * max(X - i, 0) + B * max(Y - i, 0)
    ans = min(ans, cnt)
print(ans)