A, B, C, X, Y = map(int, input().split())
 
cost_temp = float('inf')
 
for i in range(max(X,Y)+1):
    cost = i * 2 * C + A * max(0, X-i) + B * max(0, Y-i)
    if cost < cost_temp:
        cost_temp = cost
 
print(cost_temp)