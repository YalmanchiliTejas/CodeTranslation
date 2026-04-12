def main():
    N, M = (int(i) for i in input().split())
    G = [[] for i in range(N)]
    for i in range(M):
        x, y = (int(i)-1 for i in input().split())
        G[x].append(y)
        G[y].append(x)
    ans = 0
    from itertools import permutations
    for p in permutations(range(1, N)):
        j = 0
        # print(p)
        for i in range(N-1):
            if p[i] in G[j]:
                j = p[i]
            else:
                break
        else:
            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
