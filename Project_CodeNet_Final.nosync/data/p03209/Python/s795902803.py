def L(N, X):
    if N == 0:
        return 1

    a = 2 ** (N + 1) - 3
    b = 2 ** N - 1
    if X == 1:
        return 0
    elif X <= a + 1:
        return L(N-1, X-1)
    elif X == a + 2:
        return b + 1
    elif X <= 2 * a + 2:
        return b + 1 + L(N-1, X-a-2)
    else:
        return b * 2 + 1

def main():
    N, X = map(int, input().split())
    print(L(N,X))


if __name__ == "__main__":
    main()