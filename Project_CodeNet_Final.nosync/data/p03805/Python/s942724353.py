def main():
    import sys
    input = sys.stdin.buffer.readline
    from itertools import permutations
    N, M = (int(i) for i in input().split())
    edge = [[] for _ in range(N)]
    for i in range(M):
        a, b = (int(i) for i in input().split())
        edge[a-1].append(b-1)
        edge[b-1].append(a-1)

    ans = 0
    for p in permutations(range(1, N)):
        v = 0
        for nv in p:
            if nv in edge[v]:
                v = nv
            else:
                break
        else:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
