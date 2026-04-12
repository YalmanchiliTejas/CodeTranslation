
def main():
    A = list(input())
    N = len(A)
    K = int(input())

    DP0 = [[0] * (K+1) for _ in range(N+1)]
    DP1 = [[0] * (K+1) for _ in range(N+1)]

    DP0[0][0] = 1
    #print(A)
    for i in range(1, N+1):
        for k in range(0, K+1):
            if k >= 1:
                DP0[i][k] = (int(A[i-1]) == 0) * DP0[i-1][k] + (int(A[i-1]) >= 1) * DP0[i-1][k-1]
                DP1[i][k] = DP0[i-1][k-1]*max(int(A[i-1])-1, 0) + DP0[i-1][k]*(int(A[i-1]) >= 1) + DP1[i-1][k-1]*9 + DP1[i-1][k]
            else:
                DP0[i][k] = (int(A[i-1]) == 0) * DP0[i-1][k]
                DP1[i][k] = DP0[i-1][k]*(int(A[i-1]) >= 1) + DP1[i-1][k]
            #print("#===#")
            #print(DP0)
            #print(DP1)

    print(DP0[N][K] + DP1[N][K])

if __name__ == "__main__":
    main()
