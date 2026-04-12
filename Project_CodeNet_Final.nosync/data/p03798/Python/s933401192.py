N = int(input())
s = input()
s += s[:2]
rec = [[""] * (N + 2) for i in range(4)]
rec[0][0] = "S"
rec[0][1] = "S"
rec[1][0] = "S"
rec[1][1] = "W"
rec[2][0] = "W"
rec[2][1] = "S"
rec[3][0] = "W"
rec[3][1] = "W"
k = -1
for i in range(4):
    for j in range(1, N + 1):
        if s[j] == "o":
            if rec[i][j] == "S":
                rec[i][j + 1] = rec[i][j - 1]
            else:
                if rec[i][j - 1] == "S":
                    rec[i][j + 1] = "W"
                else:
                    rec[i][j + 1] = "S"
        else:
            if rec[i][j] == "S":
                if rec[i][j - 1] == "S":
                    rec[i][j + 1] = "W"
                else:
                    rec[i][j + 1] = "S"
            else:
                rec[i][j + 1] = rec[i][j - 1]

if rec[0][0] == rec[0][N] and rec[0][1] == rec[0][N + 1]:
    k = 0
elif rec[1][0] == rec[1][N] and rec[1][1] == rec[1][N + 1]:
    k = 1
elif rec[2][0] == rec[2][N] and rec[2][1] == rec[2][N + 1]:
    k = 2
elif rec[3][0] == rec[3][N] and rec[3][1] == rec[3][N + 1]:
    k = 3

if k == -1:
    print(-1)
else:
    print("".join(rec[k][:N]))
