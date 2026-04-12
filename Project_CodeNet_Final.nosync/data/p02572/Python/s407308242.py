n= int(input())
a = list(map(int,input().split()))
allsum= sum(a)
ans = 0
for i in range(n):
    allsum = allsum -a[i]
    ans += a[i]*allsum
o = ans % (10**9+7)
print(o)