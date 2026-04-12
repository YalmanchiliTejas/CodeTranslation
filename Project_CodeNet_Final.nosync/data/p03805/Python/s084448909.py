def c_One_stroke_Path(N, M, E):
    import itertools
    edge = [[] for j in range(N + 1)]
    for a, b in E:
        edge[a].append(b)
        edge[b].append(a)

    ans = 0
    route = itertools.permutations(range(2, N + 1), N - 1)
    for r in route:
        if not r[0] in edge[1]:
            # 頂点1からrが示す次の行き先に行くことができない
            continue
        count = 0
        for i in range(len(r)):
            if count == len(r) - 1:
                # すべての頂点を回れた
                ans += 1
                break
            if not r[i + 1] in edge[r[i]]:
                # 次の行き先に行くことができなかった
                break
            count += 1

    return ans

N,M = [int(i) for i in input().split()]
E = [[int(i) for i in input().split()] for j in range(M)]
print(c_One_stroke_Path(N, M, E))