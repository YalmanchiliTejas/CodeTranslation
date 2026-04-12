a,b,c,x,y = map(int, input().split())
cost = {x:a, y:b}
s = min(x,y) * c * 2 + abs(x - y) * cost[max(x,y)]
t = max(x,y) * c * 2
u = a * x + b * y

print(min([s, t, u]))
