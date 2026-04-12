def abc054_c_one_stroke_paths():
    N, M = map(int, input().split())

    # create graph G
    G = {}
    for m in range(M):
        a, z = map(int, input().split())
        G[a] = G.get(a, [])
        G[a].append(z)
        G[z] = G.get(z, [])
        G[z].append(a)

    # print(G)

    # find all paths
    if G.get(1, 0) == 0:
        print(0)
        return

    def dfs(a, path):
        path.append(a)
        if len(path) == N:
            return 1

        paths = 0
        for z in G.get(a):
            if z in path:
                continue
            paths += dfs(z, path[:])

        return paths

    print(dfs(1, []))


##########
if __name__ == "__main__":
    abc054_c_one_stroke_paths()
