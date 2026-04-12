# https://atcoder.jp/contests/abc095/tasks/arc096_a
"""
別解(定数時間)
https://atcoder.jp/contests/abc095/submissions/10226556
"""

A,B,C,X,Y = map(int,input().split())

ans = float("inf")

# ABピザを2枚1組で考える -> ABセット
# i: ABセットの個数
for i in range(10**5 + 1):
    ans = min(ans, i*(2*C) + max(0, X-i)*A + max(0, Y-i)*B)

print(ans)