from collections import deque
n = int(input())
a = [int(input()) for _ in range(n)]

a = sorted(a)
que1 = deque([a[0]])
for i in range(1, n):
    if i%4 == 1:
        que1.appendleft(a[-(2*(i//4)+1)])
    elif i%4 == 2:
        que1.append(a[-(2*(i//4)+2)])
    elif i%4 == 3:
        que1.appendleft(a[2*(i//4)+1])
    else:
        que1.append(a[i//2])

que2 = deque([a[-1]])
for i in range(n-1):
    if i%4 == 0:
        que2.appendleft(a[i//2])
    elif i%4 == 1:
        que2.append(a[2*(i//4)+1])
    elif i%4 == 2:
        que2.appendleft(a[-(i//2+1)])
    else:
        que2.append(a[-(i//2+2)])

sum1 = 0
i = que1.popleft()
while len(que1) > 0:
    j = que1.popleft()
    sum1 += abs(i - j)
    i = j

sum2 = 0
i = que2.popleft()
while len(que2) > 0:
    j = que2.popleft()
    sum2 += abs(i-j)
    i = j
    
print(max(sum1, sum2))
