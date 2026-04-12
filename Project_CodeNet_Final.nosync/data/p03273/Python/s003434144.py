H,W = map(int,input().split())
L = [input() for i in range(H)]
X = [False for i in range(W)]
Y = [False for i in range(H)]

for y in range(H) :
    for x in range(W) :
        if L[y][x] == "#" :
            X[x] = True
            Y[y] = True

for y in range(H) :
    if Y[y] == True :
        ANS = []
        for x in range(W) :
            if X[x] == True :
                ANS.append(L[y][x])
        print("".join(ANS))
