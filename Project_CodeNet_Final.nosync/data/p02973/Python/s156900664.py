import bisect

words = lambda t : list(map(t, input().split()))
n = int(input())
a = []
for i in range(n):
    a.append(-1 * int(input()))

b = []
b.append(a[0])

for i in range(1,n):
    x = a[i]
    x_ind = bisect.bisect_right(b,x)
    #print(x, x_ind, b)
    if x_ind >= len(b):
        b.append(x)
    else:
        b[x_ind] = x

print(len(b))
