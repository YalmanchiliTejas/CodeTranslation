from collections import deque
N = int(input())
A = []
for i in range(N):
    A.append(int(input()))
A.sort()
Aup = deque(A)
Adown = deque(A)
up = deque([])
down = deque([])
up.append(Aup.pop())
down.append(Adown.popleft())

i = 0
while True:
    for i in range(2):
        if i % 2 == 0:
            if up[0] > up[-1]:
                up.appendleft(Aup.popleft())
            else:
                up.append(Aup.popleft())

            if down[0] < down[-1]:
                down.appendleft(Adown.pop())
            else:
                down.append(Adown.pop())

        else:
            if up[0] < up[-1]:
                up.appendleft(Aup.pop())
            else:
                up.append(Aup.pop())

            if down[0] > down[-1]:
                down.appendleft(Adown.popleft())
            else:
                down.append(Adown.popleft())

        if len(Aup) == 0:
            break
    if len(Aup) == 0:
        break
    i += 1
upans = 0
downans = 0
up = list(up)
down = list(down)
for i in range(1,N):
    upans += abs(up[i] - up[i-1])
    downans += abs(down[i] - down[i-1])
print(max(upans,downans))
