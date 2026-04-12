A,B,C,X,Y = map(int,input().split())

minprice = 10 ** 10
XY_max = max(X,Y)

for i in range(XY_max + 1):
    nokori_X = max(X - i,0)
    nokori_Y = max(Y - i,0)

    tmp = i * 2 * C + nokori_X * A + nokori_Y * B
    minprice = min(tmp,minprice)

if minprice == 10 ** 10:
    minprice = 0

print(minprice)