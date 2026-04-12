A,B,C,X,Y = map(int, input().split())
result = A*X + B*Y

for c2 in {0, X, Y}:
    a = max(X - c2, 0)
    b = max(Y - c2, 0)
    fee = int(a*A + b*B + c2*C *2)
    # if (fee < result):
    #     print(a,b,c2,fee)
    result = min(fee,result)

print(result)