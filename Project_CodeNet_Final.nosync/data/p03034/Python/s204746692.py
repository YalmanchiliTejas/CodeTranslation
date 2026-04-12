def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    S = list(map(int, input().split()))

    X = [[0] for _ in range(N)]
    Y = [[0] for _ in range(N)]
    for k in range(1, N):
        for i in range(1, N):
            if i*k >= N:
                break
            X[k].append(X[k][-1] + S[i*k])
    for k in range(1, N):
        for i in range(1, N):
            if i*k >= N:
                break
            Y[k].append(Y[k][-1] + S[-i*k-1])
    ans = 0
    for k in range(1, N):
        for i in range(N):
            if i*k == N-1-i*k:
                break
            if k*(i-1) == N-1-i*k:
                break
            if k*(i+1) >= N-1:
                break
            ans = max(ans, X[k][i] + Y[k][i])
    print(ans)


if __name__ == '__main__':
    main()
