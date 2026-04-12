h, w = map(int, input().split())
A = []
for i in range(h):
    A.append(list(input()))
c = 0
for i in range(h):
    for j in range(w):
        if A[i][j] == "#":
            c += 1
if c > h+w-1:
    print("Impossible")
else:
    i = 0
    j = 0
    f = False
    for _ in range(h+w-1):
        if i + 1 < h  and A[i+1][j] == "#":
            i += 1
        elif j + 1 < w and A[i][j+1] == "#":
            j += 1
        if i == h-1 and j == w-1 and A[i][j] == "#":
            f = True
    print("Possible")