from math import ceil
A,B,C,X,Y=list(map(int,input().split()))

# ABピザを買わないと
x=A*X+B*Y
#ABピザをいくつか買う時
if X>=Y:
    y=C*2*Y+A*ceil((2*X-2*Y)/2)
else:
    y=C*2*X+B*ceil((2*Y-2*X)/2)
#ABピザのみで買う時
z=C*2*max(X,Y)
    
print(min(x,y,z))