from collections import deque

n = int(input())
an = list(map(int, input().split(' ')))

d = deque()

for i in range(n):
    if i % 2 == 0:
        d.append(an[i])
    else:
        d.appendleft(an[i])

if n % 2 == 1:
    d.reverse()
    
result = list(map(str, d))
print(' '.join(result))
