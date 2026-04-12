import bisect
n = int(input())
a = []
for i in range(n):
    temp = int(input())
    a.append(temp)
a.reverse()
b = [a[0]]
counter = 1
for i in range(1,n):
    if a[i] >= b[-1]:
        counter += 1
        b.append(a[i])
    else:
        ind = bisect.bisect_right(b,a[i])
        b[ind] = a[i]
print(counter)