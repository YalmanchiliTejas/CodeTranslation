def c_one_stroke_path(N, M, E):
    from itertools import permutations
    edge = [[] for j in range(N + 1)]
    for a, b in E:
        edge[a].append(b)
        edge[b].append(a)

    ans = 0
    # 頂点1を始点としてこの順番に頂点を回れるか試す
    routes = permutations(range(2, N + 1), N - 1)
    for route in routes:
        r = [1] + list(route)
        for i in range(len(r) - 1):
            if not r[i + 1] in edge[r[i]]:
                break  # 次の行き先に行くことができなかった
        else:
            ans += 1  # すべての頂点を訪れることができた
    return ans

N,M = [int(i) for i in input().split()]
E = [[int(i) for i in input().split()] for j in range(M)]
print(c_one_stroke_path(N, M, E))
