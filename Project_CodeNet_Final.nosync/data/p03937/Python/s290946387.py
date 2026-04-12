H,W=map(int,input().split())
A=[list(input()) for i in range(H)]
H,W=H-1,W-1
if not (A[0][0]==A[-1][-1]=="#"):
    print("Impossible")
    exit()

h=0
w=0
while H>h or W>w:
    if H>h and W>w:
        if A[h+1][w]=="#" and  [1 for w_ in range(w+1,W+1) if A[h][w_]=="#"] or A[h][w+1]=="#" and  [1 for h_ in range(h+1,H+1) if A[h_][w]=="#"]:
            print("Impossible")
            exit()
        elif A[h+1][w]=="#":
            h+=1
        elif A[h][w+1]=="#":
            w+=1
        else:
            print("Impossible")
            exit()
    elif H>h and A[h+1][w]=="#":
        h+=1
    elif W>w and A[h][w+1]=="#":
        w+=1
    else:
        print("Impossible")
        exit()

print("Possible")
