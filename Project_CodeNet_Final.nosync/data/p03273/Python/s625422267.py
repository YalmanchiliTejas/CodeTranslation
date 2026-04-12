import sys

readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)
INF = float('inf')

H, W = map(int, readline().split())

white_y = [0] * H
white_x = [1] * W

masu = []
for i in range(H):
    yoko = list(readline().decode("utf-8"))
    if not "#" in yoko:
        white_y[i] = 1
    for j, x in enumerate(yoko):
        if x == "#":
            white_x[j] = 0
    masu.append(yoko)

# print(white_y)
# print(white_x)

for i in range(H):
    if white_y[i] == 1:
        continue
    s = ""
    for j in range(W):
        if white_x[j] == 1:
            continue
        s += masu[i][j]
    print(s)
    