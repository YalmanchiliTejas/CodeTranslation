from collections import deque
n = int(input())
a = list(map(int, input().split()))

d = deque()

for i in range(0,n,2):
    d.append(a[i])

for i in range(1,n,2):
    d.appendleft(a[i])

if n % 2 == 0:
    for i in d:
        print(i)
else:
    d.reverse()
    for i in d:
        print(i)