from collections import deque


que = deque()

n = int(input())
seq = list(map(int, input().split()))

for i in range(n):
    if i%2 == 0:
        que.append(seq[i])
    else:
        que.appendleft(seq[i])

if n%2 != 0:
    que.reverse()



print(*que)

