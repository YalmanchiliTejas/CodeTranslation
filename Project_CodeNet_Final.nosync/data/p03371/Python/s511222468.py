A, B, C, X, Y = map(int, input().split())

ans = 10**18
for i in range(0, 2*max(X, Y)+2, 2):
    ans = min(ans, i * C + max(X-(i//2), 0) * A + max(Y-(i//2), 0) * B)
print(ans)