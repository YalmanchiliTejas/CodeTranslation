from itertools import permutations

def main():
    N, M = map(int, input().split())
    G = [set() for _ in range(N)]
    for _ in range(M):
        a, b = map(int, input().split())
        G[a - 1].add(b - 1)
        G[b - 1].add(a - 1)
    r = 0
    for p in permutations(range(1, N)):
        f = 0
        for i in p:
            if i not in G[f]:
                break
            f = i
        else:
            r += 1
    return r

print(main())
