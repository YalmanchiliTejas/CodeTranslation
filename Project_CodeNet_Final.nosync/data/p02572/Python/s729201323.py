N = int(input())
a = [int(x) for x in input().split()]

sm = 0
for i in range(len(a)):
    sm += a[i]

ans = 0
for i in range(len(a)):
    ans += a[i]*(sm-a[i])

ans //= 2
print(ans%(10**9+7))