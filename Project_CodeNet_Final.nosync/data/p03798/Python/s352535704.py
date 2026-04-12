n = int(input())
s = input()

ans = ["SS", "SW", "WS", "WW"]

for i in range(4):
    for j in range(1, n):
        if s[j] == "o" and ans[i][j] == "S":
            ans[i] += ans[i][j-1]
        elif s[j] == "o" and ans[i][j] == "W":
            ans[i] += "W" if ans[i][j-1] == "S" else "S"
        elif s[j] == "x" and ans[i][j] == "S":
            ans[i] += "W" if ans[i][j-1] == "S" else "S"
        else:
            ans[i] += ans[i][j - 1]

    if ans[i][0] == ans[i][n]:
        if ans[i][n-1] == ans[i][1] and ((s[0] == "o" and ans[i][0] == "S") or (s[0] == "x" and ans[i][0] == "W")):
            print(ans[i][:-1])
            break
        if ans[i][n-1] != ans[i][1] and ((s[0] == "o" and ans[i][0] == "W") or (s[0] == "x" and ans[i][0] == "S")):
            print(ans[i][:-1])
            break
else:
    print(-1)