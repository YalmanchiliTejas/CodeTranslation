import bisect

n = int(input())
a = [int(input()) for i in range(n)][::-1]
LIS = [a[0]]
for i in a[1:]:
    if i >= LIS[-1]:
        LIS.append(i)
    else:
        LIS[bisect.bisect_right(LIS, i)] = i
print(len(LIS))