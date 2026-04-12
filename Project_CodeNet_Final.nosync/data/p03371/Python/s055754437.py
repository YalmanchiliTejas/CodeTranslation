def calcPizza(k, mai):
    return k*mai

a,b,c,x,y = [int(i) for i in input().split(' ')]
mins = min(x,y)

asum = calcPizza(a, x)
bsum = calcPizza(b, y)
absum = calcPizza(c,mins*2)
if x > mins:
    atmp= calcPizza(a,x-mins)
    abtmp= calcPizza(c,(x-mins)*2)
    absum += min(atmp,abtmp)
elif y > mins:
    btmp = calcPizza(b,y-mins)
    abtmp = calcPizza(c,(y-mins)*2)
    absum += min(btmp,abtmp)
print(min(asum+bsum, absum))