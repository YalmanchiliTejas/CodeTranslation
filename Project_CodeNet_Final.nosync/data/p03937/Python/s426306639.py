import sys
h, w = map(int, input().split())
f = [list(map(str, input().rstrip())) for _ in range(h)]

for i in range(h - 1):
    for j in range(w - 1):
        if (f[i][j] == "#" and f[i][j + 1] == "#" and f[i + 1][j] == '#') or (f[i][j + 1] == "#" and f[i + 1][j] == "#" and f[i + 1][j + 1] == "#"):
            print("Impossible")
            sys.exit()

print("Possible")