n = int(input())
a = list(map(int,input().split()))

waru = 7 + 1000000000

asum = 0

for i in a:
  asum += i
  
mod = 0
asum -= a[0]
for i in range(len(a)-1):

  mo = (a[i] * (asum)) % waru
  mod += mo

  asum -= a[i+1]
  
print(mod % waru)