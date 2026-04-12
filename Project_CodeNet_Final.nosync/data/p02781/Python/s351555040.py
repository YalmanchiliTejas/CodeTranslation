import math
import sys
sys.setrecursionlimit(10**9)


def comb(n, r):  # 普通のcombination計算
    if r < 0 or r > n:
        return 0
    else:
        n1 = math.factorial(n)
        n21 = math.factorial(n - r)
        n22 = math.factorial(r)
        ans = n1 // (n21 * n22)
        return ans


"""
solve(i, k, smaller)
:= i桁目以降について、0以外の値を残りk個使用可能という状況を考える。
このときi桁目までの部分が「等しい」か「strictに小さくなっている」かを
smallerフラグによって分岐する。
"""


def solve(i, k, smaller):  # 再帰

    # print(i, k, smaller)

    if i == N:
        if k == 0:
            return 1
        else:
            return 0

    if k == 0:
        return 1

    if smaller == True:
        return comb(N - i, k) * pow(9, k)

    else:
        if S[i] == "0":
            return solve(i + 1, k, False)
        else:
            """
            ex. S = 314159　の場合
            000000〜099999 := a
            100000〜299999 := b
            300000〜314159 := c　のように場合分け
            """
            a = solve(i + 1, k, True)
            b = solve(i + 1, k - 1, True) * (int(S[i]) - 1)
            c = solve(i + 1, k - 1, False)
            return a + b + c


# 問題文ではNだが、文字列として扱うのでSと名付ける
S = input()
# Sの桁数、問題文のNとは違う
N = len(S)
K = int(input())

ans = solve(0, K, False)
print(ans)
