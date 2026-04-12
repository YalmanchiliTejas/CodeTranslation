while 1:
    S = input()
    if S == "#":
        break

    S = S.split("/")
    board = []
    for S_row in S:
        row = []
        for s in S_row:
            if s == "b":
                row.append("b")
            else:
                for _ in range(int(s)):
                    row.append(".")
        board.append(row)

    a, b, c, d = map(int, input().split())
    board[a-1][b-1], board[c-1][d-1] = board[c-1][d-1], board[a-1][b-1]

    ans = ""
    for b_row in board:
        cnt = 0
        for b in b_row:
            if b == ".":
                cnt += 1
            else:
                if cnt != 0:
                    ans += str(cnt)
                    cnt = 0
                ans += "b"
        if cnt != 0:
            ans += str(cnt)
        ans += "/"

    print(ans[:-1])
