from bisect import bisect
n = int(input())
a = [-int(input()) for i in range(n)]
x = [a[0]]
for i in range(1,n):
    if x[-1]<=a[i]: x.append(a[i])
    else: x[bisect(x,a[i])] = a[i]
print(len(x))