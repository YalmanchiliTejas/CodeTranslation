N = int(input())
x = N * 800
y = 0
discount = 0
if N >= 15:
    discount = N / 15
    y = int(discount) * 200
else:
    y = 0
print(x - y)