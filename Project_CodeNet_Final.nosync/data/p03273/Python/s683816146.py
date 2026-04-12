H,W = map(int,input().split())
a = [input() for i in range(H)]

y = [False]*H
x = [False]*W

for i in range(H):
    for j in range(W):
        if a[i][j] == "#":
            y[i] = True
            x[j] = True
            
for i in range(H):
    if y[i] == True:
        for j in range(W):
            if x[j] == True:
                print(a[i][j],end="")
        print()