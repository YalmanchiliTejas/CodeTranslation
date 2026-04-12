import math
N = int(input())
sets = math.floor(N / 15)
discount = sets * 200
cost = N * 800 - discount
print(cost)
