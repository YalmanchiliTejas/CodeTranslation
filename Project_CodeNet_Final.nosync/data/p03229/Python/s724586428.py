n = int(input())
a = [int(input()) for _ in range(n)]
a = sorted(a)
b = abs###
# min, max
p,q = a[0],a[-1]
res = b(p-q)
for i in range(n//2-1):
    # i+1, n-2-i
    res += b(p-a[n-2-i])
    res += b(q-a[i+1])
    p,q = a[i+1],a[n-2-i]
if n%2==1:
    c = a[n//2]
    res += max(b(p-c),b(q-c))
print(res)
