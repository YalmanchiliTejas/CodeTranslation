from math import factorial


def cmb(n, r):
    if n-r < 0 or r < 0:
        return 0
    else:
        return factorial(n) // (factorial(r) * factorial(n - r))


def solve(n, k):
    if n == [] or sum(n) == 0:
        if k == 0:
            return 1
        else:
            return 0

    for i in range(len(n)):
        if n[i] != 0:
            break

    n = n[i:]

    l = len(n)
    ans = 0

    # n-1桁からKこ取る
    tmp1 = (9**k)*cmb(l-1, k)

    # 最上位から1つ（最上位の数以外）とる。
    tmp2 = (n[0]-1)*(9**(k-1))*cmb(l-1, k-1)

    # 最上位からその数をとる。
    if k > 1:
        tmp3 = solve(n[1:], k-1)
    elif k == 1:
        if len(n) == 1:
            tmp3 = 1
        else:
            tmp3 = solve(n[1:], k-1)
    else:
        tmp3 = 0

    ans = tmp1 + tmp2 + tmp3
    return int(ans)


n = list(map(int, input()))
k = int(input())

print(solve(n, k))
