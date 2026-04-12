
def submit():
    n, x = map(int, input().split())

    L = [0 for _ in range(n + 1)] # 総枚数
    P = [0 for _ in range(n + 1)] # パティ枚数
    L[0] = 1
    P[0] = 1

    for i in range(n):
        L[i + 1] = 3 + 2 * L[i]
        P[i + 1] = 1 + 2 * P[i]

    def search(l, r):
        if l == 0:
            return 1
        if r == 1:
            return 0

        r -= 1 # パンを食べる
        if L[l - 1] > r:
            return search(l - 1, r)
        if L[l - 1] == r:
            return P[l - 1]
        if L[l - 1] + 1 == r:
            return 1 + P[l - 1]

        r -= L[l - 1] + 1 # 下半分を食べる
        if L[l - 1] > r:
            return search(l - 1, r) + 1 + P[l - 1]
        if L[l - 1] == r or L[l - 1] + 1 == r:
            return 1 + 2 * P[l - 1]
        
    print(search(n, x))


submit()