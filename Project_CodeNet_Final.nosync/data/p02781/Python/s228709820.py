# https://atcoder.jp/contests/abc154/tasks/abc154_e
# 桁DPっぽいよなぁ => O

"""
memo
dp0[i][j]
  上からi桁目まで決めて，0でない桁がj個あり
  Nより小さいことが確定している (less)
dp1[i][j]
  上からi桁目まで決めて，0でない桁がj個あり
  Nより小さいことが確定していない (i桁目まで同じ)

通常の再帰
rec
"""

S = input()
K = int(input())
N = len(S)

def com(N, R):
    if R < 0 or R > N:
        return 0
    if R == 1:
        return N
    elif R == 2:
        return N * (N - 1) // 2
    elif R == 3:
        return N * (N - 1) * (N - 2) // 6
    else:
        raise NotImplementedError("NIE")


# 再帰呼出し
def rec(i, k, smaller):
    if i == N:
        return 1 if k == 0 else 0
    if k == 0:
        return 1
    if smaller:
        # 残っている桁数からk個を選び，それぞれ9^kのパターンがある
        return com(N - i, k) * pow(9, k)
    else:
        if S[i] == '0':
            return rec(i + 1, k , False)
        else:
            zero = rec(i + 1, k, True)
            aida = rec(i + 1, k - 1, True) * (int(S[i]) - 1)
            ichi = rec(i + 1, k - 1, False)
            return zero + aida + ichi

ans = rec(0, K, False)
print(ans)