price_A, price_B, price_AB, num_A, num_B = map(int,input().split())
AandB = price_A * num_A + price_B * num_B
if num_A >= num_B:
    minAB = price_AB*num_B*2 + price_A*(num_A-num_B)
else:
    minAB = price_AB*num_A*2 + price_B*(num_B-num_A)
maxAB = price_AB * max(num_A, num_B) * 2
print(min(AandB, minAB, maxAB))