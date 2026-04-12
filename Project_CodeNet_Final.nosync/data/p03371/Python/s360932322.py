A, B, C, X, Y = map(int, input().split())

ans = 10 ** 18
for i in range(0, 2 * max(X, Y) + 1, 2):
    tmpx = X - (i // 2)
    if tmpx <= 0:
        tmpx = 0
    tmpy = Y - (i // 2)
    if tmpy <= 0:
        tmpy = 0
    ans = min(ans, (i * C) + (tmpx * A) + (tmpy * B))

print(ans)