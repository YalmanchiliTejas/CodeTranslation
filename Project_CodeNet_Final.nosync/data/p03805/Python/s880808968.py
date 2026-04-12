#!/usr/bin/python3

from itertools import permutations

def main():
    ans = 0
    n, m = map(int, input().split())
    G = [[] for _ in range(n) ]

    for _ in range(m):
        a, b = map(int, input().split())
        a -= 1; b -= 1;
        G[a] += [b]
        G[b] += [a]

    a = list(permutations(range(1, n)))

    for i in a:
        ok = True
        for j in range(len(i)):
            tmp = False
            if j == 0:
                for e in G[0]:
                    if e == i[j]:
                        tmp = True
            else:
                for e in G[i[j-1]]:
                    if e == i[j]:
                        tmp = True
            if not tmp:
                ok = False
        if ok:
            ans += 1

    print(ans)

main()