import sys
sys.stdin.readline

def main():
    N, K = input(), int(input())
    S = "0"*(100-len(N))+N
    DP = [[[0] * 2 for _ in range(K+2)] for _ in range(101)]
    DP[0][0][0] = 1
    for i in range(100):
        for j in range(K+1):
            DP[i+1][j][0] += DP[i][j][0] * (S[i] == "0")
            DP[i+1][j+1][0] += DP[i][j][0] * (S[i] != "0")
            DP[i+1][j][1] += DP[i][j][1] + DP[i][j][0] * (int(S[i]) > 0)
            DP[i+1][j+1][1] += DP[i][j][1] * 9 + DP[i][j][0] * max(0, int(S[i])-1)
    print(sum(DP[-1][K]))

if __name__ == "__main__":
    main()