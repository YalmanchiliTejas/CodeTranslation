# https://atcoder.jp/contests/abc095/tasks/arc096

# 値段,枚数
A, B, C, X, Y = map(int, input().split())

ans = float("inf")
for i in range(10 ** 5 * 2):
    ans = min(ans, max(X - i, 0) * A + max(Y - i, 0) * B + 2 * i * C)

print(ans)
