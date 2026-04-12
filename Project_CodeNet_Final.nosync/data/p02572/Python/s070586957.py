import itertools
x = 10**9 + 7
n = int(input())
a = list(map(lambda i: i % x , map(int, input().split(" "))))
sum_a = []
prev = 0
for i in a:
    sum_a.append(prev + i)
    prev = prev + i

ans = 0
for i in range(n):
    ans += (a[i] * (sum_a[n-1] - sum_a[i] )) % x
print(ans % x)