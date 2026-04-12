A,B,C,X,Y = map(int,input().split())
addition = 0
if X > Y:
    addition = A
elif X < Y:
    addition = B
    
print(min(A*X + B*Y, 2*C*min(X,Y) + abs(X-Y)*addition, 2*C*max(X,Y)))