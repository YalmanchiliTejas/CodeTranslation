n = int(input())
li = list(map(int,input().split()))
licumsum = 0
for i in range(n):
    licumsum += li[i]
asum = 0
for i in range(n):
    asum += li[i]*(licumsum - li[i])
    if asum >= (10**9 + 7)*2:
        asum = asum % ((10**9 + 7)*2)
if asum//2 >= 10**9 + 7:
    print(asum//2-(10**9+7))
else:
    print(asum//2)