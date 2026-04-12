def solve():

    H, W = [int(i) for i in input().split()]
    alist = [input() for i in range(H)]

    cols = [False]*H
    rows = [False]*W

    for i in range(H):
        for j in range(W):
            if alist[i][j] == '#':
                cols[i] = True
                rows[j] = True

    for i in range(H):
        if cols[i]:
            for j in range(W):
                if rows[j]:
                    print(alist[i][j], end="")

            print()


if __name__ == "__main__":
    solve()
