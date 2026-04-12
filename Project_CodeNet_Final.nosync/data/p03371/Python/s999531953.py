a, b, c, x, y = list(map(int, input().split()))

min_money=2*5000*10**5
for nc in range(0,2*10**5+1,2):
    if nc > 2*x and nc > 2*y:
        break
    if nc > 2*x:
        money = (y-nc//2)*b + nc*c
    elif nc > 2*y:
        money = (x-nc//2)*a + nc*c
    else:
        money = (x-nc//2)*a + (y-nc//2)*b + nc*c
    if min_money > money:
        min_money = money
            
print(min_money)