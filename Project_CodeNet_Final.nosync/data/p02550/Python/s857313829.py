mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, x, mod = map(int, input().split())

    seen = [0] * mod
    ans = 0
    A = []
    ii = -1
    for i in range(N):
        if seen[x] == 0:
            seen[x] = 1
        elif seen[x] == 1:
            A.append(x)
            seen[x] = 2
        elif seen[x] == 2:
            ii = i
            break
        ans += x
        x = (x * x) % mod
    if ii == -1:
        print(ans)
    else:
        rem = N - ii
        ans += sum(A) * (rem // len(A))
        rem %= len(A)
        for j in range(rem):
            ans += A[j]
        print(ans)


if __name__ == '__main__':
    main()
