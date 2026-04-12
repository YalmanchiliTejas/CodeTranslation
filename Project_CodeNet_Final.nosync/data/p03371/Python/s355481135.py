A,B,C,X,Y = map(int,input().split())
if(A+B<2*C):
    print(A*X+B*Y)
else:
    X,Y,temp = X - min(X,Y),Y - min(X,Y),(C*2)*min(X,Y)
    if(C*2 <= A and C*2 <= B):
        print(temp+2*C*X+2*C*Y)
    elif(C*2 <= A and C*2 > B):
        if(Y == 0):
            print(temp+C*2*X)
        else:
            print(temp+B*Y)
    elif(C*2 > A and C*2 <= B):
        if(Y == 0):
            print(temp+A*X)
        else:
            print(temp+C*2*Y)
    else:
        print(temp+A*X+Y*B)