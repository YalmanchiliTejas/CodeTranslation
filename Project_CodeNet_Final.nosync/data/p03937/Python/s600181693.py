h, w = list(map(int, input().split()))
grid = [input() for _ in range(h)]

x = 0
y = 0

while True:
    c = []
    neighbours = 0
    if x != w-1:
        c.append([x+1, y, 1])
    if y != h-1:
        c.append([x, y+1, 3])

    for coords in c:
        if grid[coords[1]][coords[0]] == "#":
            neighbours += 1
            x2 = coords[0]
            y2 = coords[1]

    if neighbours != 1 and not (x == w-1 and y == h-1):
        print("Impossible")
        break

    c = []
    neighbours = 0
    if x != 0:
        c.append([x-1, y, 0])
    if y != 0:
        c.append([x, y-1, 2])

    for coords in c:
        if grid[coords[1]][coords[0]] == "#":
            neighbours += 1

    if neighbours > 1:
        print("Impossible")
        break

    if x == w-1 and y == h-1:
        print("Possible")
        break

    x = x2
    y = y2