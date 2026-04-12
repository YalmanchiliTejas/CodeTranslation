import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    N = input()
    K = int(input())
    n_len = len(N)

    dp = [[[0] * (K + 2) for _ in [0, 0]] for _ in range(n_len + 1)]
    dp[0][0][0] = 1

    for i in range(n_len):
        ni = int(N[i])
        for isLess in [0, 1]:
            for not_0 in range(K+1):
                num = 10 if isLess else ni + 1
                dp[i+1][isLess or 0 < ni][not_0] += dp[i][isLess][not_0]
                for j in range(1, num):
                    dp[i+1][isLess or j < ni][not_0+1] += dp[i][isLess][not_0]

    print(dp[n_len][1][K] + dp[n_len][0][K])

if __name__ == '__main__':
    main()