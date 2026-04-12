A,B,C,X,Y = map(int, input().split())
mn = min((A+B)/2, C)
ans1 = 0
ans1 += min(X,Y)*2*mn
if X > Y:
    ans1 += A*(X-Y)
elif Y> X:
    ans1 += B*(Y-X)
ans2 = 0
ans2 += C*max(X, Y)*2
print(int(min(ans1,ans2)))