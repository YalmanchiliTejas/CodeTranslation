icase=0
if icase==0:
    h,w=map(int,input().split())
    a=[]
    aid=["."]*w
    for i in range(h):
        ai=list(input())
        if ai!=aid:
            a.append(ai)
    b=[""]*len(a)
    for j in range(0,w):
        for i in range(len(a)):
            if a[i][j]=="#":
                break
        if a[i][j]=="#":
            for ii in range(len(a)):
                b[ii]=b[ii]+a[ii][j]
    for i in range(len(a)):
        print(b[i])
                