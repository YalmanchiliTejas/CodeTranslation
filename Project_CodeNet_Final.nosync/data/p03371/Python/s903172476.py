a,b,c,x,y=map(int,input().split())
abget=min(a+b,2*c)
aget=min(a,2*c)
bget=min(b,2*c)
xyget=min(x,y)
ans=xyget*abget
if x>y:
  ans+=(x-xyget)*aget
elif y>x:
  ans+=(y-xyget)*bget
print(ans)
