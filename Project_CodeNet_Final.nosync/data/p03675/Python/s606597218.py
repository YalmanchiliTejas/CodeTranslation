from collections import deque
N = int(input())
line = input().split()
Q = deque([])

flag = 0 if (N % 2 != 0) else 1
for i in range(N):
    if (i % 2 == 0):
        if (flag):
            Q.append(line[i])
        else:
            Q.appendleft(line[i])
    else:
        if (flag):
            Q.appendleft(line[i])
        else:
            Q.append(line[i])

print(' '.join(Q))
