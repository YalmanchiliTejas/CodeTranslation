A,B,C,X,Y=map(int,input().split())
if Y<X:
    A,B=B,A
    X,Y=Y,X
print(min(2*C,A+B)*X+min(2*C,B)*(Y-X))
