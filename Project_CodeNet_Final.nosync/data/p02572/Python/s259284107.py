MOD = 10**9+7

n = int(input())
a=list(map(int,input().split()))

sum_a=sum(a)%MOD
total=0
for i in range(len(a)):
    sum_a=(sum_a-a[i])%MOD
    total = (total+sum_a*a[i])%MOD

print(total%MOD)