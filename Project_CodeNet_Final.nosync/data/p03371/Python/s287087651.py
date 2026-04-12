A,B,C,X,Y = map(int,input().split())
ans = 0
ans += min(X,Y)*min((A+B),C*2)
if X > Y:
    ans += (X-Y)*min(A,C*2)
else:
    ans += (Y-X)*min(B,C*2)
print(ans)