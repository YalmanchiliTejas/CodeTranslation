n = int(input())
a = list(map(int, input().split()))

"""
allsum = 0
for i in range(n-1):
    allsum += a[i] * sum(a[i+1:])
print(allsum % (10**9+7))
"""
s, s2 = 0, 0
for i in range(n):
    s += a[i]
    s2 += a[i] * a[i]
print(((s*s - s2)//2) % (10**9+7))
