a, b = map(int, input().split())
c = [list(input())for _ in range(a)]
x = y = 0
c[x][y] = "."
while True:
    moved = False
    if x < a-1:
        if c[x+1][y] =="#":
            c[x+1][y] = "."
            x += 1
            if not moved:
                moved = not moved
    if y < b-1:
        if c[x][y+1] == "#":
            c[x][y + 1] = "."
            y += 1
            if not moved:
                moved = not moved
    if x == a-1 and y == b-1:
        for i in range(a):
            for j in range(b):
                if c[i][j] == "#":
                    print("Impossible")
                    exit()
        print("Possible")
        exit()
    if not moved:
        print("Impossible")
        exit()