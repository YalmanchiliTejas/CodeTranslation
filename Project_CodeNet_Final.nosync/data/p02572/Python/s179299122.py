import itertools
n = int(input())
a = list(map(int,input().split()))
mod = 1000000007

total = 0
for i in range(len(a)-1):
    if(i == 0):
        before_sum = sum(a) - a[i]
    else:
        before_sum -= a[i]
    total += a[i] * (before_sum) 


print(total%mod)

