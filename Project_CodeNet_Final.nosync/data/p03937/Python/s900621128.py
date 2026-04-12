a,b = map(int,input().split(" "))
ar = []
for i in range(a):
    l = list(input())
    ar.append(l)
count = 0
for i in range(a):
    for j in range(b):
        if ar[i][j] == "#":
            count += 1
if count == a + b - 1:
    print("Possible")
else:
    print("Impossible")