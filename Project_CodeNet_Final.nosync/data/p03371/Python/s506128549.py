A,B,C,X,Y = map(int,input().split())
ans = float("inf")
for i in range(0,2*max(X,Y)+2,2):
    yen = A*max(0,X-(i//2))+C*i+B*max(0,Y-(i//2))
    ans = min(ans,yen)
print(ans)
