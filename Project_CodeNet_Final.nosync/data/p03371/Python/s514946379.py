A,B,C,X,Y=map(int,input().split())
cost=A*X+B*Y
Z=max(X,Y)
for i in range(0,2*Z+1,2):
    x=max(0,X-(i//2))
    y=max(0,Y-(i//2))
    cost=min(cost,C*i+A*x+B*y)
print(cost)