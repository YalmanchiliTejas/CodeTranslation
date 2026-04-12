def solve():
    n = int(input())
    a = tuple(int(x) for x in input().split())

    memo = tuple([None] * n for _ in range(n))
    for i, aa in enumerate(a):
        memo[i][i] = aa

    for l in range(n - 2, -1, -1):
        for r in range(l + 1, n):
            memo[l][r] = max(a[r] - memo[l][r - 1], a[l] - memo[l + 1][r])

    print(memo[0][n - 1])


if __name__ == '__main__':
    solve()

# [l,r]を
# l:=配列aの右端から左にシフト
# r:=lと一致する位置からn-1まで右にシフト
# と考えると、l==rは既にメモ化済みなので、l=n-2以前、r=l+1以降を調べればよい
# 漸化式で使う値は、
# lがより右にいるときの計算結果（前のループで計算済み）と
# rがより左にいるときの計算結果（一番左でもl==rなので計算済み）
# なので、参照する値がNoneになることはなく、Noneのチェックは不要になる
