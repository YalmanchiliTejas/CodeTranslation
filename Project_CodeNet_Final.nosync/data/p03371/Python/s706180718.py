
a,b,c,x,y = map(int,input().split())
INF = 10**9
upp = max(x,y)*2
ans = INF

for i in range(upp+1):
    money = i*c
    half = i // 2
    if x > half:
        money += (x-half)*a
    if y > half:
        money += (y-half)*b
    if money < ans:
        ans = money
print(ans)