A,B,C,X,Y=map(int,input().split())
tmp0 = X*A + Y*B
tmp1 = max(X,Y)*2*C
if X>Y:
    tmp2 = Y*2*C + (X-Y)*A
else:
    tmp2 = X*2*C + (Y-X)*B
print(min(tmp0,tmp1,tmp2))