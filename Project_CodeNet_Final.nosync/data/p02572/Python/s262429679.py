n = int(input())
a = list(map(int, input().split()))
sum = sum(a)
s = 0
c = 0
for i in range(n - 1):
    s += a[i]
    c = (c + (a[i] * (sum - s)))  % (10**9 + 7)
print(c)