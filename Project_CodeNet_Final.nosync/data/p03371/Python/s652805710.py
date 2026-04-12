A,B,C,X,Y = map(int,input().split())

#全部Cで買うとき
a = 2*C*min(X,Y) + 2*C*(max(X,Y)-min(X,Y))

#片方を全部Cで買うとき
if X > Y:
    b = 2*C*Y + (X-Y)*A
elif Y > X:
    b = 2*C*X + (Y-X)*B
else:
    b = a
    
#全部AとBで買うとき
c = A*X + B*Y

print(min(a,b,c)) 