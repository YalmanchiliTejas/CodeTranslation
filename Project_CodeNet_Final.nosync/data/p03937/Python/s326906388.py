h, w = map(int, input().split())
a = []
for i in range(h):
    a.append(list(input()))

now_x = 0
now_y = 0
while(True):
    if now_x+1 <w and a[now_y][now_x+1] == "#":
        a[now_y][now_x] = "."
        now_x+=1

    elif now_y+1 <h and a[now_y+1][now_x] == "#":
        a[now_y][now_x] = "."
        now_y+=1

    else:
        a[now_y][now_x] = "."
        break

check = True
for i in a:
    for j in i:
        if j == "#":
            check = False

print("Possible" if check else "Impossible")