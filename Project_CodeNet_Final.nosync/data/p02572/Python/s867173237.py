import itertools

n = int(input())
a = list(map(int,input().split()))
s = sum(a)
ini = []
for i in range(n):
    s -= a[i]
    tmp = a[i]*s
    ini.append(tmp)
print(sum(ini)%(10**9+7))