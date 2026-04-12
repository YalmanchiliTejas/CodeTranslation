h,w = map(int,input().split())

maze = [[0] for _ in range(h)]
for i in range(h):
    maze[i] = list(input())

flag = True
prev = 0
for row in maze:
    if "#" not in row:
        flag = False
        break
    left = row.index("#")
    if prev != left:
        flag = False
        break
    for r in range(left,w):
        if row[r] == "#":
            right = r
        else:
            break
    check_r = w-1-row[::-1].index("#")
    if check_r != right:
        flag = False
        break
    prev = right
if flag:
    print('Possible')
else:
    print('Impossible')