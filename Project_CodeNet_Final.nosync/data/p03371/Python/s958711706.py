A,B,C,X,Y = map(int,input().split())

CtoAB1 =0
CtoAB2 =0
AandB =0

if X >= Y:
    CtoAB1=2*C*Y+A*(X-Y)
    CtoAB2=2*C*X
else:
    CtoAB1=2*C*X+B*(Y-X)
    CtoAB2=2*C*Y

AandB=A*X+B*Y

print(min(CtoAB1,CtoAB2,AandB))