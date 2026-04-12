h,w = map(int,input().split())
l = [list(input()) for i in range(h)]

x = 0
y = 0
while True:
    if l[x][y] == "#":
        l[x][y] = "."
        if y < w-1 and l[x][y+1] == "#":
            y += 1
        elif x < h-1 and l[x+1][y] == "#":
            x += 1
        else:
            break
    else:
        break
for i in l:
    if "#" in i:
        print("Impossible")
        exit()
print("Possible")