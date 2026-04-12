h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
x = y = 0
a[0][0] = "."
while True:
    if x + 1 < w and y + 1 < h:
        if a[y][x+1] == a[y+1][x]:
            print("Impossible")
            exit()
        elif a[y][x+1] == "#":
            x += 1
            a[y][x] = "."
        elif a[y+1][x] == "#":
            y += 1
            a[y][x] = "."
    elif y + 1 >= h:
        x += 1
        if a[y][x] != "#":
            print("Impossible")
            exit()
        else:
            a[y][x] = "."
    elif x + 1 >= w:
        y += 1
        if a[y][x] != "#":
            print("Impossible")
            exit()
        else:
            a[y][x] = "."
    if x == w - 1 and y == h - 1:
        for i in range(h):
            for j in range(w):
                if a[i][j] == "#":
                    print("Impossible")
                    exit()
        print("Possible")
        exit()
