n = int(input())

li = list(map(int,input().split()))
li_1 = []
mod = 10**9+7

a = 0
for i in range(1,len(li)):
    total = li[i] * (a +li[i-1])
    a += li[i-1]
    li_1.append(total)

print(sum(li_1)%mod)