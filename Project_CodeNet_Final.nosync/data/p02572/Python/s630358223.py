import itertools
n = int(input())
a = list(map(int, input().split()))
suma = sum(a)-a[0]
ans = 0
p = 10 ** 9+7
for i in range(len(a)-1):
    ans += a[i]*suma
    suma -= a[i+1]
    ans = ans%p
print(ans)