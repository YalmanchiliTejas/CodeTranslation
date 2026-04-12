import sys

A,B,C,X,Y = list(map(int,input().split()))

if A+B < 2*C:
    print(A*X+B*Y)
else:
    pre = []
    pre.append(max(X,Y)*2*C)
    if X>Y:
        #X>YならY枚Bピザを用意してX-Y枚Aピザを買うのも候補
        pre.append(Y*2*C+(X-Y)*A)
    elif X<Y:
        #X枚Aピザを用意してY-X枚Bピザ
        pre.append(X*2*C+(Y-X)*B)
    else:

        pre.append(Y*2*C+(X-Y)*A)
        pre.append(X*2*C+(Y-X)*B)
    print(min(pre))
