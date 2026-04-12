N, S = map(int, input().split())
A = [0] + list(map(int, input().split()))
mod = 998244353

dp = [0] * (S + 1)
dp2 = [0] * (S + 1)

"""
dp[i][j] = (i個までの数を使ってj点とる組み合わせ)
としたはいいが、f(L, R)をf(1,L)とf(1, R)に分解できずに爆死したのが敗因。

各(L, R)に対してdpするとTLEになるから手詰まりになると思ったわけだけど、
上のdpテーブルを各iに対して使い回しつつ、新たなdpテーブル[1, 0, 0, ...]を
作成して「元のdpテーブルに加算しておけば」dpテーブル一個で1番目スタート、2番目スタート、
..., L番目スタートのdpテーブル全てを考えられる！
（解説放送前半を参考）
"""

# i == 0の時
dp[0] = 1
ans = 0

# i >= 1の時
for i in range(1, N + 1):
    for j in range(S + 1):
        if j - A[i] < 0:
            dp2[j] = dp[j]
        else:
            dp2[j] = dp[j] + dp[j - A[i]]
    ans += dp2[S]
    ans %= mod

    dp = dp2 # deepcopyしなくてもこれで十分なはずだし、ポインタ渡しなので高速？
    dp[0] += 1
    dp2 = [0] * (S + 1)

print(ans)
