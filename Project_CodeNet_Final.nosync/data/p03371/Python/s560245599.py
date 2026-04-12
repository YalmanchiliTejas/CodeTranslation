A, B, C, X, Y = map(int, input().split())

least_price = float("inf")
less_list = sorted([X, Y])

for i in range(less_list[1]+1):
    num_A = X- i
    num_B = Y - i
    
    if num_A <= 0 :
        num_A = 0
    if num_B <= 0:
        num_B = 0

    total_price = C * 2*i +  A * num_A + B * num_B
    if least_price > total_price:
            least_price = total_price
    else:
        pass

print(least_price)