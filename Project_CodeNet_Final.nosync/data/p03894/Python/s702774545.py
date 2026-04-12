n, q = [ int(v) for v in input().split() ]
num = [ 0 for i in range(n) ]
num[0] = 1
num[1] = 2
p = 0
for i in range(q):
    a, b = [ int(v)-1 for v in input().split() ]
    num[a], num[b] = num[b], num[a]
    if num[a] == 1:
        p = a
    elif num[b] == 1:
        p = b
    if p > 0:
        num[p-1] = 2
    if p < n-1:
        num[p+1] = 2
print(n - num.count(0))