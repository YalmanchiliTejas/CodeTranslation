A,B,C,X,Y = map(int,input().split())
ans = A*X+B*Y
for i in range(1,max(X,Y)+1):
    a = A*(X-i) if X-i>0 else 0
    b = B*(Y-i) if Y-i>0 else 0
    tmp = a+b+C*i*2
    ans = min(ans,tmp)
print(ans)
