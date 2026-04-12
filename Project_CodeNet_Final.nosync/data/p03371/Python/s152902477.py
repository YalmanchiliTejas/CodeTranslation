A,B,C,X,Y = map(int,input().split())

# あり得るのはすべてA,Bで買う．少ない方を満たすまで
import math
max_money = A*X + B*Y

# 次にAをすべて！ABで買ってみる
if X>Y:
    max_money = min(2*X*C,max_money)
else:
    max_money = min(max_money,2*X*C + (Y-X)*B)


# 次にBをすべて！ABで買ってみる
if Y>X:
    max_money = min(2*Y*C,max_money)
else:
    max_money = min(max_money,2*Y*C + (X-Y)*A)

print(max_money)
