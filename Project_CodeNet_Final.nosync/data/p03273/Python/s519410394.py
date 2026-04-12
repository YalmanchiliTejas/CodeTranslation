H, W = map(int, input().split(" "))
A=[]
for i in range(H):
    tmp = input()
    A.append ([c  for c in tmp])
    
# print (A)

h=H
w=W
for i in range(H-1,-1,-1):
    cnt = 0    
    for j in range(W):
        if A[i][j] == ".":
            cnt += 1


    if cnt == W:
        h -= 1
        for ii in range(i, H-1):
            for jj in range(W):
                A[ii][jj] = A[ii+1][jj]

for j in range(W-1,-1,-1):
    cnt = 0    
    for i in range(h):
        if A[i][j] == ".":
            cnt += 1


    if cnt == h:
        w -= 1
        for jj in range(j, W-1):
            for ii in range(h):
                A[ii][jj] = A[ii][jj+1]

def printA(A, h, w):
    for i in range(h):
        st = ""
        for j in range(w):
            st += (A[i][j])

        print (st)    

printA(A, h, w)