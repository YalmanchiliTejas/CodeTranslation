[h,w] = [int(i) for i in input().split()]
a = []
b = 0
for i in range(h):
    a.append(input())
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            b = b + 1

if b == (h+w)-1:
    print("Possible")
else:
    print("Impossible")
