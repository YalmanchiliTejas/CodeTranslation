a,b,c,x,y = map(int, input().split())

pair = min(x,y)
cost = 0

if a + b > 2 * c:
    cost = 2 * c * pair
else:
    cost = (a + b) * pair

if (x - pair) > (y - pair):
    if a > 2 * c:
        cost = cost + 2 * c * (x - pair)
    else:
        cost = cost + a * (x - pair)

else:
    if b > 2 * c:
        cost = cost + 2 * c * (y - pair)
    else:
        cost = cost + b * (y - pair)

print(cost)