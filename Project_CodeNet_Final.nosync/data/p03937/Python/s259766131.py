H,W=list(map(int,input().split()))

A = [input() for i in range(H)]

prevend=0
for i in range(H):
    for j in range(W):
        if A[i][j] == '#' and j < prevend:
            print ("Impossible")
            exit()
        elif j>0 and A[i][j-1] == '#' and A[i][j] == '.':
            prevend = j-1
            break
        elif j==W-1:
            prevend =W-1

prevend = 0
for j in range(W):
    for i in range(H):
        if A[i][j] == '#' and i < prevend:
            print ("Impossible")
            exit()
        elif i>0 and A[i-1][j] == '#' and A[i][j] == '.':
            prevend = i-1
            break
        elif i==H-1:
            prevend =H-1


print("Possible")
