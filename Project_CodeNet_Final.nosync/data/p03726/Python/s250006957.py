def main():
    n = int(input())
    ab = [list(map(int, input().split())) for _ in [0]*(n-1)]
    g = [set() for _ in [0]*n]
    [g[a-1].add(b-1) for a, b in ab]
    [g[b-1].add(a-1) for a, b in ab]
    only = []
    sign = [False]*n
    for i in range(n):
        if len(g[i]) == 1:
            only.append(i)
    while only:
        i = only.pop()
        if not g[i]:
            print("Second")
            return
        j = g[i].pop()
        g[j].remove(i)
        if sign[i] and not g[j]:
            print("First")
            return
        if not sign[i] and sign[j]:
            print("First")
            return
        if not sign[j] and not sign[i]:
            sign[j] = True
        if len(g[j]) == 1:
            only.append(j)


main()
