h, w = map(int, input().split())
table = []
for i in range(h):
    table.append(list(input()))
poss = True
for i in range(h-1):
    for j in range(w-1):
        if table[i][j] == "#":
            if (table[i+1][j]=="#" and table[i][j+1]=="#") or (table[i+1][j]=="." and table[i][j+1]=="."):
                poss = False
for i in range(1, h):
    if table[i][w-2]=="#" and table[i-1][w-1]=="#":
        poss = False
for i in range(1, w):
    if table[h-1][i-1]=="#" and table[h-2][i]=="#":
        poss = False

if poss:
    print("Possible")
else:
    print("Impossible")
