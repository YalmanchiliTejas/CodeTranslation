n = int(input())
a = list(map(int,input().split()))

s = sum(a)
aa = [a[i]*a[i] for i in range(n)]
s2 = sum(aa)

print((s**2 - s2) //2%(10**9+7))
