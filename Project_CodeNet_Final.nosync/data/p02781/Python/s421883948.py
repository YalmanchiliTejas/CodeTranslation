# coding: utf-8


def solve(*args: str) -> str:
    N = list(map(int, '0' + (args[0])))
    k = int(args[1])

    d = len(N)-1
    F = [[0]*(k+1) for _ in range(d+1)]
    U = [[0]*(k+1) for _ in range(d+1)]

    U[0][0] = 1
    for i in range(1, d+1):
        for j in range(1, k+1):
            # set zero on i_th digit
            F[i][j-1] += F[i-1][j-1] + U[i-1][j-1]*(0 < N[i])
            U[i][j-1] += U[i-1][j-1]*(0 == N[i])

            # set non-zero on i_th digit
            F[i][j] += max(0, N[i]-1)*U[i-1][j-1] + 9*F[i-1][j-1]
            U[i][j] += U[i-1][j-1]*(0 < N[i])

    return str(sum(x[k] for x in F+U))


if __name__ == "__main__":
    print(solve(*(open(0).read().splitlines())))
