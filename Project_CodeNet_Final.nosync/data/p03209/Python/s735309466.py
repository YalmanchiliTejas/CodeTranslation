import sys
input = sys.stdin.readline


def f(P, S, L, X, count):
    if L == 0:
        return count + P[0]

    if X == 1:
        return count
    elif X <= 1 + S[L-1]:
        return f(P, S, L-1, X-1, count)
    elif X == 1 + S[L-1] + 1:
        return count + P[L-1] + 1
    elif X <= 1 + S[L-1] + 1 + S[L-1]:
        return f(P, S, L-1, X-(1+S[L-1]+1), count+P[L-1]+1)
    else:
        return count + P[L]


def main():
    N, X = map(int, input().split())

    P = [0] * (N+1)
    S = [0] * (N+1)
    P[0] = 1
    S[0] = 1
    for i in range(N):
        P[i+1] = 2*P[i] + 1
        S[i+1] = 2*S[i] + 3

    ans = f(P, S, N, X, 0)
    print(ans)


if __name__ == "__main__":
    main()
