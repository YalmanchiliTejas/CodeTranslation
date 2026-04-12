A,B,C,X,Y = map(int,input().split())

ans1 = A*X+B*Y
ans2 = C*min(X,Y)*2
if X < Y :
    ans2 += min(C*2,B)*(Y-X)
else :
    ans2 += min(C*2,A)*(X-Y)
ans = min(ans1,ans2)
print(ans)
