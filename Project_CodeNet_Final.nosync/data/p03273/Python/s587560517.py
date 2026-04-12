H,W = map(int,input().split())

MAP=  [[0 for i in range(W)] for i in range(H)]

HLIST=[0 for i in range(H)]
WLIST=[0 for i in range(W)]

for h in range(H):
    L=list(input())
    MAP[h]=L
    for w in range(W):
        if(MAP[h][w]=="#"):
            HLIST[h]+=1
            WLIST[w]+=1
for h in range(H):
    if(HLIST[h]!=0):
        for w in range(W):
            if(WLIST[w]!=0):
                if(MAP[h][w]=="#"):
                    print("#",end="")
                else:
                    print(".",end="")
        print("")

