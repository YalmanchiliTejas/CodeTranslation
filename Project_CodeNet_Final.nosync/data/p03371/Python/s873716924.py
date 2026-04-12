A,B,C,X,Y=map(int,input().split())
p=A*X+B*Y
for i in range(100001):
  p=min(p,i*2*C+A*max(0,X-i)+B*max(0,Y-i))
print(p)