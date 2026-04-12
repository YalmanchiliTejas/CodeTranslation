import sys
H,W = map(int, input().split())
x_pos = 0
for _ in range(H):
    a = input()
    for i in range(W):
        if i<x_pos and a[i]=="#":
            print("Impossible")
            sys.exit()
        if a[i]=="#":
            x_pos = max(x_pos, i)
print("Possible")