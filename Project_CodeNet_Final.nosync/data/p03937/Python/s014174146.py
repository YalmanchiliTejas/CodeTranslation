h, w = [int(i) for i in input().split()]
adj = [["" for _ in range(w)] for j in range(h)]
for i in range(h):
    _tmp = input()
    for j in range(w):
        adj[i][j] = _tmp[j]
# for i in range(h):
    # print(adj[i])
for i in range(h):
    for j in range(w):
        if (i > 0 or j > 0) and adj[i][j] == "#":
            okFlag = False
            if i > 0 and adj[i - 1][j] == "#":
                okFlag = True
                adj[i - 1][j] = "."
            elif j > 0 and adj[i][j - 1] == "#":
                okFlag = True
                adj[i][j - 1] = "."
            if not okFlag:
                print("Impossible")
                # print("[{},{}]".format(i, j))
                exit()
print("Possible")
# for i in range(len(adj)):
    # print(adj[i])