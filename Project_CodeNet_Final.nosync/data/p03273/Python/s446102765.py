h,w=map(int,input().split())
board=[""]*h
for i in range(h):
    board[i]=input()
boolx=[0]*h
booly=[0]*w
for i in range(h):
    for j in range(w):
        if board[i][j]=="#":
            boolx[i]=1
            booly[j]=1
for i in range(h):
    if boolx[i]:
        for j in range(w):
            if booly[j]:
                print(board[i][j],end="")
        print()
