A, B, C, X, Y = map(int, input().split())

ans = 0

# まずABを買う
ab = min(A + B, C*2)
buy = min(X, Y)
ans += ab * buy

X -= buy
Y -= buy

# 残りを買う
ans += min(A, 2 * C) * X
ans += min(B, 2 * C) * Y


print(ans)
