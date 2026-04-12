A,B,C,X,Y=map(int,input().split())
ans=[]
if X>=Y:
    X,Y=Y,X
    A,B=B,A

ans.append(A*X+B*Y)
ans.append(2*C*X+B*(Y-X))
ans.append(2*C*max(X,Y))

print(min(ans))