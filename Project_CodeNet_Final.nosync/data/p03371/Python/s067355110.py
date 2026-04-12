A, B, C, X, Y = map(int,input().split())
money = 10**10
for i in range(10**5+1):
    money = min(money, 2*i*C + A*max(0, X-i) + B * max(0, Y-i))
print(money)