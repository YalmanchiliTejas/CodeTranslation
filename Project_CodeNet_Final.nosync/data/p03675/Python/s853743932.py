from collections import deque
n = int(input())
b = deque()
Alist = list(map(int,input().split()))
i = 1
if n%2 == 0:
    for a in Alist:
        if i%2 == 0:
            b.appendleft(a)
        else:
            b.append(a)
        i += 1
else:
    for a in Alist:
        if i%2 == 0:
            b.append(a)
        else:
            b.appendleft(a)
        i +=1
print(*b)