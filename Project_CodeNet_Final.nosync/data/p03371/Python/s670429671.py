a,b,c,x,y=map(int,input().split())
l=[]
for i in range(max(x,y)+1):
  l.append(i*2*c+max((x-i),0)*a+max((y-i),0)*b)
print(min(l))