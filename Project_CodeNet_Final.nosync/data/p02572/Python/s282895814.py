n = int(input())
li = list(map(int, input().split()))
res = 0
sum1 = sum(li)
sum2 = 0
m = 10**9 + 7
for i in range(0, len(li)-1):
    sum2 += li[i]
    res = (res + li[i]*(sum1-sum2))%m
print(res)