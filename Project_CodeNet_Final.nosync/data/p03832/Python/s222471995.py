import sys

def MI(): return map(int, sys.stdin.readline().split())

md = 10 ** 9 + 7

n_max = 1005
fac = [1]
for i in range(1, n_max + 1): fac.append(fac[-1] * i % md)
ifac = [1] * (n_max + 1)
ifac[n_max] = pow(fac[n_max], md - 2, md)
for i in range(n_max - 1, 1, -1): ifac[i] = ifac[i + 1] * (i + 1) % md

def main():
    n, a, b, c, d = MI()
    pn = b - a + 1  # 班人数の種類数
    dp = [[0] * (n + 1) for _ in range(pn + 1)]
    # dp[i][j]...i番目の人数の班まで決めて全体でj人が決まったときの場合の数
    dp[0][0] = 1
    ps = 0
    for i in range(pn):
        p = i + a  # 班人数
        low = n - (p + b) * (b - p + 1) * d // 2
        up = (a + p - 1) * (p - a) * d // 2
        for j in range(max(low, 0), min(n, up) + 1):
            pre = dp[i][j]
            if pre == 0: continue
            dp[i + 1][j] += pre
            dp[i + 1][j] %= md
            r = n - j  # 残りの人数
            for g in range(c, d + 1):
                if j + p * g > n: break
                dp[i + 1][j + p * g] += pre * fac[r] * ifac[r - p * g] * ifac[g] * pow(ifac[p], g, md)
                dp[i + 1][j + p * g] %= md
        ps += p
    print(dp[pn][n])

main()
