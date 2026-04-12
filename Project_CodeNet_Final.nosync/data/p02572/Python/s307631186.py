mod = 1000000007
N = int(input())
A = list(map(lambda x: int(x) % mod, input().split(" ")))

"""
累積話を計算しておく: O(N)
"""
_sum = 0
for i in range(N):
    _sum += A[i]
    _sum %= mod

"""
1重ループ内で下記を行う: O(N)

- 端のブロックを累積和から崩す（減算）
- 端のブロックと累積和をかける
- modをとる
"""
ans = 0
for i in range(N):
    # 累積和の端のブロックを崩す
    _sum -= A[i]

    ans += A[i] * _sum
    ans %= mod

print(ans)
