while True:
    S = input()
    if S == "#":
        break

    a, b, c, d = map(int, input().split())

    hasBall = [[False for _ in range(10)] for _ in range(10)]

    rows = S.split('/')
    H = len(rows)
    for h, row in enumerate(rows, start=1):
        cur = 1
        colsize = 0
        for ch in row:
            if ch == 'b':
                hasBall[h][cur] = True
                colsize += 1
                cur += 1
            else:
                colsize += int(ch)
                cur += int(ch)
        W = colsize

    # for h in range(H+2):
    #     for w in range(W+2):
    #         print(hasBall[h][w], end="")
    #     print()

    hasBall[a][b] = False
    hasBall[c][d] = True

    rows = []
    for h in range(1, H+1):
        streak = 0
        row = ""
        for w in range(1, W+1):
            if hasBall[h][w]:
                if streak:
                    row += str(streak)
                    streak = 0
                row += 'b'
            else:
                streak += 1
        if streak:
            row += str(streak)

        rows.append(row)

    # for h in range(H+2):
    #     for w in range(W+2):
    #         print(hasBall[h][w], end="")
    #     print()

    print("/".join(rows))

