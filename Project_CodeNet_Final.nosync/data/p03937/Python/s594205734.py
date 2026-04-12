import sys

H,W=map(int,input().split())

A=["."*(W+2)]
T=0
for _ in range(H):
    G=input()
    A.append("."+G+".")
    T+=G.count("#")
    
A.append("."*(W+2))

x,y=1,1
U=1
while x<W or y<H:
    p=(A[y+1][x]=="#")
    q=(A[y][x+1]=="#")

    if p^q:
        if p:
            y=y+1
        else:
            x=x+1
        U+=1
    else:
        print("Impossible")
        sys.exit()

if T==U:
    print("Possible")
else:
    print("Impossible")
