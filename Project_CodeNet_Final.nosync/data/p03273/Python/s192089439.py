def resolve():
    H, W = [int(i) for i in input().split()]
    A = [input() for _ in range(H)]
    skipC = [False for _ in range(W)]
    skipR = [False for _ in range(H)]
    for i in range(H):
        if A[i] == "".join(["." for _ in range(W)]):
            skipR[i] = True
    for i in range(W):
        for j in range(H):
            if A[j][i] != ".":
                break
        else:
            skipC[i] = True

    for i in range(H):
        if skipR[i]:
            continue
        for j in range(W):
            if skipC[j]:
                continue
            print(A[i][j], end="")
        print("")


resolve()
