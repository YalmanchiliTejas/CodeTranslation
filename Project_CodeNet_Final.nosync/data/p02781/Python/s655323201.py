N = input()[::-1] # 文字列, N[0]が1の位となるように反転
K = int(input())

# N = a[0] + a[1]*10 + ... + a[n]*10^n （n+1桁）のとおく
n = len(N) - 1
# dp[i][j] = i桁以下の数字0〜999...9のうちNonzeroがj桁の数
# dp[i][4] = dp[i][-1]はダミー
dp = [[1, 0, 0, 0]] + [[0 for _ in range(5)] for _ in range(n + 1)]

for i in range(1, n + 1):
    dp[i][0] = 1
    for j in [1, 2, 3]:
        dp[i][j] = sum([9 * dp[ii][j - 1] for ii in range(0, i)])

# nzd[i] := a[i], .., a[n]のうちnonzeroの桁数
nzd = [0] * (n + 2)  # nzd[n + 1]はダミー
for i in range(n, -1, -1):
    nzd[i] = nzd[i + 1] + int(N[i] != '0')

ans = 0
for i in range(0, n):
    if N[n - i] == '0': continue
    # a[n]a[n-1]...a[n-i+1]00....0 〜 a[n]a[n-1]...a[n-i+1]09...9
    ans += dp[n - i][max(-1, K - nzd[n - i + 1])]

    # a[n]a[n-1]...a[n-i+1]d0...0 〜 a[n]a[n-1]...a[n-i+1]d9...9 for d = 1,...,a[n-i]-1
    ans += (int(N[n - i]) - 1) * dp[n - i][max(-1, K - nzd[n - i + 1] - 1)]

# a[n]a[n-1]...a[1]0 〜 a[n]a[n-1]...a[1]a[0]
if nzd[1] == K:
    ans += 1
elif nzd[1] == K - 1:
    ans += int(N[0])

print(ans)
