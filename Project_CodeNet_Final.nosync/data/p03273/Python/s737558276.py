def main():
    H, W = map(int, input().split())
    cell = [list(input()) for _ in range(H)]
    rlist = list()
    clist = list()
    for i in range(H):
        if cell[i].count(".") == W:
            rlist.append(i)
    for j in range(W):
        c = 0
        for i in range(H):
            if cell[i][j] == ".":
                c += 1
            if c == H:
                clist.append(j)
    for i in range(H):
        if i in rlist:
            pass
        else:
            for j in range(W):
                if j in clist:
                    pass
                else:
                    print(cell[i][j], end="")
            print()
main()