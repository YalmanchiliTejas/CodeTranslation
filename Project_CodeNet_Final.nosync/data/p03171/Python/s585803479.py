import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    n = int(input())
    aa = list(map(int, input().split()))
    dp = [[0] * n for _ in range(n)]
    coff = 1 if n % 2 else -1
    for i, a in enumerate(aa):
        dp[i][i] = coff * a
    # p2D(dp)
    for d in range(1, n):
        coff *= -1
        for l in range(n - 1):
            r = l + d
            if r >= n: break
            if coff == 1:
                dp[l][r] = max(dp[l + 1][r] + aa[l], dp[l][r - 1] + aa[r])
            else:
                dp[l][r] = min(dp[l + 1][r] - aa[l], dp[l][r - 1] - aa[r])
    # p2D(dp)
    print(dp[0][-1])

main()
