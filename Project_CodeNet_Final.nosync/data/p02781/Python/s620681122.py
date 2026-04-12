import sys

def solve():
    input = sys.stdin.readline
    N = input().strip("\n")
    K = int(input())
    dig = len(N)
    DP = [[0] * (K + 1) for _ in range(dig)]
    DP[0][0] = 1
    DP[0][1] = int(N[0]) - 1
    for i in range(1, dig):
        DP[i][1] = 9
        if N[i] != "0": 
            DP[i][0] = DP[i-1][0] + 1
            if DP[i-1][0] <= K: DP[i][DP[i-1][0]] += 1
            if DP[i-1][0] <= K - 1: DP[i][DP[i-1][0] + 1] += int(N[i]) - 1     
        else: DP[i][0] = DP[i-1][0]
        for j in range(1, K): DP[i][j+1] += DP[i-1][j] * 9
        for j in range(1, K + 1): DP[i][j] += DP[i - 1][j]
    if DP[dig - 1][0] == K: DP[dig - 1][K] += 1
    print(DP[dig - 1][K])
    #print(DP)

            
    return 0

if __name__ == "__main__":
    solve()