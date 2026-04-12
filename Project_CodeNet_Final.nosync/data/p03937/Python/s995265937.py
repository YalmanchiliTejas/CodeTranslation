h,w = map(int,input().split())

al = []

for _ in range(h):
   a = list(input())
   al.append(a)

i,j = 0,0
while True:
    al[i][j] = "."
    if j + 1 < w and al[i][j+1] == "#":
        al[i][j+1] = "."
        j += 1
    elif i + 1 < h and al[i+1][j] == "#":
        al[i+1][j] = "."
        i += 1
    else:
        print("Impossible")
        exit()
    if j == w-1 and i == h-1:
        break

for i in range(h):
    for j in range(w):
        if al[i][j] == '#':
            print("Impossible")
            exit()
print("Possible")

        