icase=0
if icase==0:
    x,y,z=map(int,input().split())
    n=x//(y+z)
    if x%(y+z)>=z:
        print(n)
    else:
        print(n-1)
