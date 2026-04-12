# -*- coding UTF-8 -*-

N = int(input())
a = [int(input()) for i in range(N)]
a.sort()

sum1 = a[N-1] - a[0]
sum2 = sum1
i = 0
while True:
    if i+1 == N-i-1:
        break
    sum1 += a[N-i-1] - a[i+1]
    if i+1 == N-i-2:
        break
    sum1 += a[N-i-2] - a[i]
    i += 1

i = 0
while True:
    if i == N-i-2:
        break
    sum2 += a[N-i-2] - a[i]
    if i+1 == N-i-2:
        break
    sum2 += a[N-i-1] - a[i+1]
    i += 1

max = sum1 if sum1 >= sum2 else sum2
print(max)
