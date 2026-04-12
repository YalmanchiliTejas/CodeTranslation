def main():
    n = int(input())
    a = tuple(int(x) for x in input().split())

    memo = [0] * n ** 2
    for i, aa in enumerate(a):
        memo[i * (n + 1)] = aa

    for l in range(n - 2, -1, -1):
        for r in range(l + 1, n):
            memo[l * n + r] = max(a[l] - memo[(l + 1) * n + r], a[r] - memo[l * n + r - 1])

    print(memo[n - 1])


if __name__ == '__main__':
    main()

# 連投の結果分かったこと
#
# [1]
# memoの初期化
# None => 530 ms
# 0 => 290 ms
# メモ化する配列の初期値が違うだけで、速度に大差
# Noneで初期化すると、代入時にint型に直すような処理が入るのか？
#
# [2]
# if __name__ == '__main__':
# なくすと遅くなった
# 530 ms -> 615 ms
#
# [3]
# map(int, input().split())
# int(x) for x in input().split()
# 数 msの違い？
#
# [4]
# メモ化配列の一次元化
# 287 ms よりこのコードが速ければ、一次元化した方がよい

# [l,r]を
# l:=配列aの右端から左にシフト
# r:=lと一致する位置からn-1まで右にシフト
# と考えると、l==rは既にメモ化済みなので、l=n-2以前、r=l+1以降を調べればよい
# 漸化式で使う値は、
# lがより右にいるときの計算結果（前のループで計算済み）と
# rがより左にいるときの計算結果（一番左でもl==rなので計算済み）
# なので、参照する値がNoneになることはなく、Noneのチェックは不要になる
