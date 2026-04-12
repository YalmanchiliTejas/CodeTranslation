# -*- coding: utf-8 -*-
n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))

a.sort()
# print(a)
b = [0 for _ in range(n)]
b[n//2] = a[0]
left = 1
right = n-1
for i in range(n//2):
    if i%2==0:
        b[n//2-(i+1)] = a[right]
        right -= 1
        if n//2+(i+1)<n:
            b[n//2+(i+1)] = a[right]
            right -= 1
    else:
        b[n//2-(i+1)] = a[left]
        left += 1
        if n//2+(i+1)<n:
            b[n//2+(i+1)] = a[left]
            left += 1
ans1 = 0
for i in range(n-1):
    ans1 += abs(b[i]-b[i+1])




b = [0 for _ in range(n)]
b[n//2] = a[n-1]
left = 0
right = n-2
for i in range(n//2):
    if i%2==1:
        b[n//2-(i+1)] = a[right]
        right -= 1
        if n//2+(i+1)<n:
            b[n//2+(i+1)] = a[right]
            right -= 1
    else:
        b[n//2-(i+1)] = a[left]
        left += 1
        if n//2+(i+1)<n:
            b[n//2+(i+1)] = a[left]
            left += 1
ans2 = 0
for i in range(n-1):
    ans2 += abs(b[i]-b[i+1])

print(max(ans1,ans2))
