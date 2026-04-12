# https://atcoder.jp/contests/abc095/tasks/arc096

# 値段,枚数
A, B, C, X, Y = map(int, input().split())

# C * 2 は　A + Bとなる
ans = max(X, Y) * 2 * C

ans = min(ans, A * X + B * Y)
if X > Y:
    ans = min(ans, (X - Y) * A + 2 * C * Y)

elif Y > X:
    ans = min(ans, (Y - X) * B + 2 * C * X)

print(ans)