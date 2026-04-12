from itertools import permutations
def main():
    n, m = list(map(int, input().split()))
    G = [set() for _ in range(n)]
    for _ in range(m):
        a, b = list(map(lambda x:int(x) - 1, input().split()))
        G[a].add(b)
        G[b].add(a)
    ans = 0
    for P in permutations(range(1, n)):
        pre = 0
        for p in P:
            if p not in G[pre]:
                break
            pre = p
        else:
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()
