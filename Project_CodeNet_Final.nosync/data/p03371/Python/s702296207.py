def LI(): return list(map(int,input().split()))
A,B,C,X,Y = LI()
ans = min(A*X+B*Y,C*(max(X,Y)*2))
if X!=Y:
    temp = (min(X,Y)*2)*C + (max(X,Y)-min(X,Y))*(A if X>Y else B)
    ans = min(temp,ans)
print(ans)
