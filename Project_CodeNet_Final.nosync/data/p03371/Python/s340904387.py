
A, B, C, X, Y = map(int, input().split())

if A < B:
    A, B = B, A
    X, Y = Y, X    
    
if A > C*2 and B > C*2:
    print(C*2*max(X,Y))

elif A > C*2 and B < C*2:
    print(2*C*X + B*max(0,(Y-X)))

elif A + B > C*2 :
    print(2*C*min(X,Y) + A*max(0,(X-Y)) + B*max(0,(Y-X)))

else:
    print(A*X+B*Y)