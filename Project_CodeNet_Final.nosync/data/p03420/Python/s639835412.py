# https://atcoder.jp/contests/arc091/tasks/arc091_b

n, k = map(int, input().split())
ans = 0
for i in range(1, n + 1):
    #divmod: 割り算の商と余りを同時に取得
    p, r = divmod(n, i)
    ans += p * max(0, i - k) + max(0, r - k + 1)
print(ans if k != 0 else ans - n)
