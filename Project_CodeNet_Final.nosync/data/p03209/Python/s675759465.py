a = [1 for i in range(51)]
p = [1 for i in range(51)]


def get(N, X):
    if N == 0:
        return 1 if X > 0 else 0
    elif X <= 1 + a[N-1]:
        return get(N-1, X-1)
    else:
        return p[N-1] + 1 + get(N-1, X-2-a[N-1])


def main():
    N, X = map(int, input().split())
    for i in range(N):
        a[i+1] = 2 * a[i] + 3
        p[i+1] = 2 * p[i] + 1
    ans = get(N, X)
    print(ans)


if __name__ == "__main__":
    main()
