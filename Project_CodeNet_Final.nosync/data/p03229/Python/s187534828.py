from collections import deque
n = int(input())
A = []
for _ in range(n):
    A.append(int(input()))
if n == 2:
    print(abs(A[1]-A[0]))
    exit()
A.sort()
s = sum(A)
if n % 2 == 1:
    small = 0
    for i in range(n//2):
        small += A[i]
    big = s - small
    ans1 = 2*big-2*small-A[n//2]-A[n//2+1]
    small += A[n//2]
    big = s-small
    ans2 = 2*big -2*small+A[n//2]+A[n//2-1]
    print(max(ans1,ans2))
else:
    small = 0
    for i in range(n//2):
        small += A[i]
    big = s -small
    ans1 = 2*big -2*small + A[n//2-1]-A[n//2]
    small += A[n//2]
    big = s -small
    ans2 = 2*big-2*small+A[n//2]-A[n//2+1]
    print(max(ans1,ans2))