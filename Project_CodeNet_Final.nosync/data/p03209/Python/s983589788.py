def main():
    N, X = (int(i) for i in input().split())

    A = [1] * (N+1)
    P = [1] * (N+1)
    for i in range(1, N+1):
        A[i] = 2*A[i-1] + 3
        P[i] = 2*P[i-1] + 1

    def f(N, X):
        if N == 0:
            return 0 if X <= 0 else 1
        elif X == 1:
            return 0
        elif X <= 1 + A[N-1]:
            return f(N-1, X-1)
        elif X == 2 + A[N-1]:
            return P[N-1] + 1
        elif X <= 2 + 2 * A[N-1]:
            return P[N-1] + 1 + f(N-1, X-2-A[N-1])
        elif X == 3 + 2 * A[N-1]:
            return 2 * P[N-1] + 1

    print(f(N, X))


if __name__ == '__main__':
    main()
