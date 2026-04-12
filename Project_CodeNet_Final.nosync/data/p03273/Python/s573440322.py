h,w=[int(i) for i in input().split()]

masu=[]
for i in range(h):
    gyou=list(input())
    if gyou!=["."]*w:
        masu.append(gyou)
        
def rotate(masu):
    m=len(masu)
    n=len(masu[0])
    rotatemasu=[]
    for i in range(n):
        gyou=[]
        for j in range(m):
                gyou.append(masu[m-j-1][i])
        if gyou!=["."]*m:
            rotatemasu.append("".join(gyou))
        
    return rotatemasu
for i in range(4):
    masu=rotate(masu)
for i in masu:
    print(i)