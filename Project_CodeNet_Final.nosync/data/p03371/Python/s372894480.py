A,B,C,X,Y=map(int,input().split())
l=[C*2*i+A*(X-i)+B*(Y-i) for i in range(min(X,Y)+1)]+[C*2*max(X,Y)]
print(min(l))