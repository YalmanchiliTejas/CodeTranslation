a,b,c,x,y=map(int,input().split())
z=min(x,y)
ans=min(a*z+b*z,c*z*2)+min(a*(x-z),c*2*(x-z))+min(b*(y-z),c*2*(y-z))
print(ans)