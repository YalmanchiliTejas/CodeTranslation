A,B,C,X,Y=map(int,input().split())
if A+B<2*C:print(A*X+B*Y)
else:
    if X>Y:print(min(2*Y*C+(X-Y)*A,2*X*C))
    else:print(min(2*X*C+(Y-X)*B,2*Y*C))