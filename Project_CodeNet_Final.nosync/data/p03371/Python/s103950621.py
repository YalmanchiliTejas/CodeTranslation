A,B,C,X,Y = map(int,input().split())
ans = 0
if (A+B)/2 > C:
    ans += C*2*min(X,Y)
else:
    ans += A*min(X,Y)+B*min(X,Y)
if X>Y:
    ans += (X-Y)*min(A,2*C)
elif X<Y:
    ans += (Y-X)*min(B,2*C)

print(ans)