A,B,C,X,Y=map(int,input().split())
L=[]
L.append(A*X+B*Y)
for i in range(min(X,Y)+1):
    L.append(A*X+B*Y-A*i-B*i+2*C*i)
ans=min(L)
if max(X,Y)*2*C<ans:
    ans=max(X,Y)*2*C
print(ans)