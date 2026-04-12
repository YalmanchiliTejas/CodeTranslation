# coding: utf-8


def solve(*args: str) -> str:
    n, x, m = map(int, args[0].split())

    a = x
    ret = 0
    D = [-1]*(m+1)
    for i in range(n):
        if 0 <= D[a]:
            j = a
            L = []
            while D[j] != a:
                L.append(j)
                j = D[j]
            L.append(j)
            d, r = divmod(n-i-1, len(L))
            ret += d*sum(L)+sum(L[:r+1])
            break
        ret += a
        p = a
        a = pow(a, 2, m)
        D[p] = a

    return str(ret)


if __name__ == "__main__":
    print(solve(*(open(0).read().splitlines())))
