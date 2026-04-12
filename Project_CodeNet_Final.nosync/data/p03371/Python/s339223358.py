A,B,C,X,Y = map(int,input().split())
cost = A*X+B*Y
for i in range(2*max(X,Y)+1):
    cost = min(cost,A*(max(0,X-i//2))+B*(max(0,Y-i//2))+C*i)
print(cost)