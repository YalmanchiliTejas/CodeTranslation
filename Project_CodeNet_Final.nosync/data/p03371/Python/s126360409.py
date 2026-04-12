a,b,c,x,y=map(int,input().split())
ans=10000000000
for i in range(0,max(x,y)*2+1,1):
    if x-i/2<=0 and y-i/2<=0:
        aa=0
        bb=0
    elif x-i/2<=0 and y-i/2>0:
        aa=0
        bb=y-i/2
    elif y-i/2<=0 and x-i/2>0:
        aa=x-i/2
        bb=0
    else:
        aa=x-i/2
        bb=y-i/2
    ab=aa*a+bb*b+i*c
    ans=min(ans,ab)
print(int(ans))