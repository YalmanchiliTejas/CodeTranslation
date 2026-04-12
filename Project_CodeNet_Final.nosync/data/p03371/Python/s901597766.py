A, B, C, X, Y = map(int, input().split())
cntA = 0
cntB = 0
cntC = 0
value = 0
if 2*C<=A+B:
    #Cで買いそろえた方が安いので
    #(max(X, Y)-abs(X-Y))*2枚は買うことになる
    Cmaisu = (max(X, Y)-abs(X-Y))*2
    value += C * Cmaisu
    if (2*C<=A and X>Y) or (2*C<=B and X<Y):
        #abs(X-Y)枚についても2Cが安けりゃCで買う
        value += C * abs(X-Y) * 2
    else:
        if X>Y:
            value += A*(X-Y)
        else:
            value += B*(Y-X)
else:
    value += A*X+B*Y
print(value)