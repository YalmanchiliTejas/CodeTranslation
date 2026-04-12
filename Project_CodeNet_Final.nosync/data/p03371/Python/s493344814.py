a,b,c,x,y=map(int,input().split())

cmax=max(x,y)*2
zmin=(a+b)*10**5
for nc in range(0,cmax+1,2):
    na=max(x-nc//2,0)
    nb=max(y-nc//2,0)
    z=a*na+b*nb+c*nc
    zmin=min(zmin,z)
    
print(zmin)
