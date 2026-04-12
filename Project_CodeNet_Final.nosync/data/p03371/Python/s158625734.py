A,B,C,X,Y = map(int,input().split())
l = []
for c in range(0,max(2*X,2*Y)+1,2):
    l.append(A*max(0,(X-c/2)) + B*max(0,(Y-c/2)) + C*c)
print(int(min(l)))