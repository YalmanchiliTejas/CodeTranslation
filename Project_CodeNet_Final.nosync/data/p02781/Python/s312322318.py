import sys
sys.setrecursionlimit(10**6)

def main():
    n = input().rstrip()
    k = int(input())
    dp = [[[0 for l in range(2)] for j in range(k + 1)] for i in range(len(n) + 1)]
    dp[0][0][0] = 1
    for i in range(len(n)):
        for j in range(k+1):
            for l in range(2):
                x = int(n[i])
                for d in range(10):
                    n_i = i+1
                    n_j = j
                    n_l = l
                    if d != 0:
                        n_j += 1
                    if n_j > k:
                        continue
                    if l == 0:
                        if d > x:
                            continue
                        if d < x:
                            n_l = 1
                    dp[n_i][n_j][n_l] += dp[i][j][l]
    print(dp[len(n)][k][0] + dp[len(n)][k][1])

if __name__ == '__main__':
    main()