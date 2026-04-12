n = int(input())
mod = 10**9 + 7
a = [int(x)%mod for x in input().split()]
allsum = sum(a)
s = 0
for i in range(n):
    allsum = allsum -a[i]
    s += a[i]*allsum
print(s%mod)