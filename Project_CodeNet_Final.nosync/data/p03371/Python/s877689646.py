a,b,c,x,y = map(int, input().split())
min_price = 10**100
for n_ab in range(0, 2*max(x, y) + 1, 2):
    price = c * n_ab
    rest_x = x - n_ab//2
    if rest_x <= 0:
        rest_x = 0
    rest_y = y - n_ab//2
    if rest_y <= 0:
        rest_y = 0 
    price += rest_x * a + rest_y * b
    min_price = min(min_price, price)

print(min_price)