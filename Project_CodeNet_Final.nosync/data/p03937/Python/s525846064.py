import sys

h, w = map(int, input().split())
a = [[i for i in input()] for j in range(h)]

board = [[-1 for i in range(w)] for j in range(h)]
board[0][0] = 0

movecol = [1, 0]
moverow = [0, 1]
count = 0

# #の数を数える
for i in range(w):
    for j in range(h):
        if(a[j][i] == "#"):
            count += 1

def dfs(x, y, n):
    #これ以上進めない
    if(x >= w or y >= h or a[y][x] == "."):
        flag = -1
        return
    #右下についた
    if(x == w-1 and y == h-1):
        if(n == count):
            print("Possible")
            sys.exit()
        else:
            flag = -1

    for i in range(2):
        nextx = x + movecol[i]
        nexty = y + moverow[i]
        dfs(nextx, nexty, n+1)

dfs(0, 0, 1)
print("Impossible")
