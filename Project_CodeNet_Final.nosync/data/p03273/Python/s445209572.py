H,W = map(int,input().split())
A = [[s for s in input()] for i in range (H)]
sumh = 0
h = [False]*H
w = [False]*W
for i in range(H):
    for j in range(W):
         if A[i][j] == '#':
             h[i] = True
             w[j] = True

for i in range(H):
    if h[i] :
        for j in range(W):
            if w[j]  :
                print(A[i][j],end ='')

        print()




