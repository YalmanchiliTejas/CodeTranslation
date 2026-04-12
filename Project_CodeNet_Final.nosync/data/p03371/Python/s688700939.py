# -*- coding:utf-8 -*-
# https://atcoder.jp/contests/abc095/tasks/arc096_a

def solve():
    A, B, C, X, Y = list(map(int, input().split()))

    ans = 0
    # 用意するピザの少ない方をまず買う
    if A+B <= C*2:
        # 1枚ずつ買ったほうが安い場合
        if X <= Y:
            ans += A*X + B*X
        else:
            ans += A*Y + B*Y
    else:
        # Cを2枚買った方が安い場合
        ans += min(X, Y)*C*2

    # 残りのピザを買う
    if X >= Y:
        if A <= C*2:
            ans += (X-Y)*A
        else:
            ans += (X-Y)*C*2
    else:
        if B <= C*2:
            ans += (Y-X)*B
        else:
            ans += (Y-X)*C*2

    print(ans)


if __name__ == "__main__":
    solve()
