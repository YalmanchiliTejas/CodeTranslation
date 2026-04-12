A,B,AB,X,Y=list(map(int,input().split()))
over=0
if X > Y:
   over=A * (X-Y)
else:
   over=B * (Y-X)
print(min(A*X+B*Y,AB*max(X,Y)*2,AB*min(X,Y)*2+over))