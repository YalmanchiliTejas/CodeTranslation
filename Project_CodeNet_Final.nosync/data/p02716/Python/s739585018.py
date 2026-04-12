import sys

def solve():
    input = sys.stdin.readline
    N = int(input())
    A = [int(a) for a in input().split()]
    if N % 2 == 0:
        if N == 2: print(max(A))
        else:
            DP = [[-10 ** 20, -10 ** 20] for _ in range(N)]
            DP[0][0] = A[0]
            DP[1][1] = A[1]
            for i in range(2, N):
                DP[i][0] = max(DP[i][0], DP[i-2][0] + A[i])
                DP[i][1] = max(DP[i][1], DP[i-2][1] + A[i])
                if i > 2: DP[i][1] = max(DP[i][1], DP[i-3][0] + A[i])
            print(max(DP[N-2][0], DP[N-1][1]))
    else:
        DP = [[-10**20, -10**20, -10**20] for _ in range(N)]
        DP[0][0] = A[0]
        DP[1][1] = A[1]
        DP[2][2] = A[2]
        DP[2][0] = A[0] + A[2]
        for i in range(3, N):
            DP[i][0] = max(DP[i-2][0] + A[i], DP[i][0])
            DP[i][1] = max(DP[i-2][1] + A[i], DP[i][1])
            DP[i][2] = max(DP[i-2][2] + A[i], DP[i][2])
            if i > 2: 
                DP[i][1] = max(DP[i][1], DP[i-3][0] + A[i])
                DP[i][2] = max(DP[i][2], DP[i-3][1] + A[i])
        ans = max(DP[N-1][2], DP[N-2][1])
        ans = max(ans, DP[N-3][0])

        print(ans)

    return 0

if __name__ == "__main__":
    solve()