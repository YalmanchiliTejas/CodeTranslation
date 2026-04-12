#n = int(input())
#n,k = map(int,input().split())
#x = list(map(int,input().split()))


H,W = map(int,input().split())
A = [list(input()) for _ in range(H)]

h = 0
w = 0
A[0][0]="."

while not(h==H-1 and w==W-1):
    # print(h,w)
    if h<H-1 and w<W-1 and A[h+1][w]=="#" and A[h][w+1]=="#":
        print("Impossible")
        break

    elif h<H-1 and A[h+1][w]=="#":
        h += 1
        A[h][w] = "."

    elif w<W-1 and A[h][w+1]=="#":
        w += 1
        A[h][w] = "."
    else:
        print("Impossible")
        break

else:
    flg = 0
    for h in range(H):
        for w in range(W):
            if A[h][w]=="#":
                flg = 1
                break
    else:
        if flg:
            print("Impossible")
        else:    
            print("Possible")
