a = list(map(int,input().split()))
h = a[0]
w = a[1]
li=[input() for i in range(h)]

ans = 0
minans = 0
flag = 0
row = [False] * h
col = [False] * w
for i in range(h):
    for j in range(w):
        if li[i][j] == "#":
            row[i]=True
            col[j]= True
for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(li[i][j],end ="")
                
        print()