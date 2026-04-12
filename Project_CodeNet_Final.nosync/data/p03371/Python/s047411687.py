input_data=input()
new_input = input_data.split(" ")
# print(new_input)
A=int(new_input[0])
B=int(new_input[1])
C=int(new_input[2])
X=int(new_input[3])
Y=int(new_input[4])
min_num=min([X,Y])

#混合で作る場合
if min_num * (A+B) > min_num * 2 * C:
    price = min_num * 2* C
else:
    price = min_num*(A+B)

if min_num == X:
    if B > 2*C:
        price += 2 * C * abs(Y-X)
    else:
        price += B * abs(Y-X)
if min_num == Y:
    if A > 2*C:
        price += 2 * C * abs(Y-X)
    else:
        price += A * abs(Y-X)

print(price)