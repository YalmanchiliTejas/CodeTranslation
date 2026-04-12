X,Y,Z=(int(i) for i in input().split())
X-=Z
Y+=Z
X//=Y
print(X)