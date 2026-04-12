A,B,C,X,Y = map(int,input().split())
 
sum = 0
 
if ( (A > 2*C) and (B > 2*C) ):
    sum = 2*C*max([X,Y])
 
elif (A+B > 2*C):
    sum = min([X,Y])*2*C
    if(X<Y):
        if(B > 2*C):
            sum = sum + (Y-X)*2*C
        else:
            sum = sum + (Y-X)*B
    else:
        if(A > 2*C):
            sum = sum + (X-Y)*2*C
        else:
            sum = sum + (X-Y)*A
else:
    sum = X*A + Y*B
 
print(sum)