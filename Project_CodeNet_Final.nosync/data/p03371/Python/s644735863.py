A,B,C,X,Y = [int(i) for i in input().split()]
Sum = 0
if A+B<=2*C:
    Sum = A*X+B*Y
else:
    Min = min([X,Y])
    Sum+=Min*(2*C)
    Y-=Min;X-=Min
    if A*X+B*Y<=2*C*(X+Y):
        Sum+=A*X+B*Y
    else:
        Sum+=2*C*(X+Y)
print(Sum)