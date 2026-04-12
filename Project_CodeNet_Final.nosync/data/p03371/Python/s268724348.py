a,b,c,x,y=map(int,input().split())
d=min(a+b,c*2)
p=min(x,y)*d
if x>y:
  p+=(x-y)*min(a,c*2)
else:
  p+=(y-x)*min(b,c*2)
print(p)