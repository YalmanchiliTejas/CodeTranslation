def abc054_c_one_stroke_paths():
    import copy
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

    paths = []

    def solve(a, path):
        path.append(a)
        if len(path) == N:
            paths.append(path)
            return
        for z in G.get(a):
            p = copy.copy(path)
            if z in p:
                continue
            solve(z, p)

    solve(1, [])
    # print(paths)
    print(len(paths))


##########
if __name__ == "__main__":
    abc054_c_one_stroke_paths()
