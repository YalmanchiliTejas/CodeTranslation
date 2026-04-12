def main():
    H, W = map(int, input().split())
    board = list()

    for i in range(H):
        board.append(list(input()))

    stat = [[False for i in range(W)] for j in range(H)]

    go = True
    i = j = 0
    stat[i][j] = True
    while go:

        if (i < H) and (j + 1 < W) and board[i][j + 1] == "#":
            j = j + 1
            stat[i][j] = True
        elif (i + 1 < H) and (j < W) and board[i + 1][j] == "#":
            i = i + 1
            stat[i][j] = True
        else:
            break

    ans = True
    for i in range(H):
        for j in range(W):
            if board[i][j] == "#" and stat[i][j] == False:
                ans = False

    if ans:
        print("Possible")
    else:
        print("Impossible")
        
if __name__ == "__main__":
    main()