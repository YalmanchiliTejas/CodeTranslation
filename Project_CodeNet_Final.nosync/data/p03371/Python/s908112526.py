A,B,C,X,Y = map(int,input().split())
A_and_B = A*X + B*Y
plus1AB = -(A+B)+2*C
if(plus1AB >= 0):
    print(A_and_B)
else:
    ABs= 2*C*min(X,Y)
    amari = abs(X-Y)
    if(X>=Y):
        only = amari*A
    else:
        only = amari*B
    ABonly = amari*2*C
    if(only >= ABonly):
        print(ABs + ABonly)
    else:
        print(ABs +only )