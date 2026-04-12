h, w = list(map(int, input().split()))
maze = []
for i in range(h):
    maze.append(input())
h_li = []
for i in range(h):
    exclude = True
    for j in range(w):
        if maze[i][j] == '#':
            exclude = False
    if not exclude:
        h_li.append(i)

w_li = []
for i in range(w):
    exclude = True
    for j in range(h):
        if maze[j][i] == '#':
            exclude = False
    if not exclude:
        w_li.append(i)

for i in h_li:
    ans = ''
    for j in w_li:
        ans += maze[i][j]
    print(ans)