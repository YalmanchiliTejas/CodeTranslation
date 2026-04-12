def main():
    N, M = (int(i) for i in input().split())
    edge = [set() for _ in range(N)]
    for i in range(M):
        a, b = (int(i) for i in input().split())
        edge[a-1].add(b-1)
        edge[b-1].add(a-1)
    from itertools import permutations
    ans = 0
    for p in permutations(range(1, N)):
        u = 0
        for v in p:
            if v not in edge[u]:
                break
            u = v
        else:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
