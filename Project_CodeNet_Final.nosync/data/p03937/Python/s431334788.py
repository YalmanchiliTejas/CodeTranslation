import sys
h, w = map(int, input().split())
a = [input() for i in range(h)]
t = 0
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            if j < t:
                print("Impossible")
                sys.exit()
            t = j
print("Possible")