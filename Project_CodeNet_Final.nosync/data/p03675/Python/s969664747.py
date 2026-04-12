from collections import deque

n = int(input())
a = input().split()

S = deque()

for i in range(n):
    if (i % 2 == 1):
        S.append(a[i])
    else:
        S.appendleft(a[i])
    
if (n % 2 == 0):
    S.reverse()

print(" ".join(S))

