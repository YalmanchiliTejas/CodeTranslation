a,b,c,x,y=map(int,input().split())

yenmin=a*x+b*y
for zz in range(2*10**5+1):
    xx=max(x-zz//2,0)
    yy=max(y-zz//2,0)
    yen=a*xx+b*yy+c*zz
    if yen<yenmin:
        yenmin=yen
print(yenmin)
#print(xx,yy,zz)