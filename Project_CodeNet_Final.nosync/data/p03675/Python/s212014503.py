from collections import deque
n = int(input())
alist = deque(map(int, input().split()))

blist = deque([])
for i in range(n) :
    bi = alist.popleft()
    if (n^i)&1 == 1 :
        blist.appendleft(bi)
    else :
        blist.append(bi)

for b in blist :
    print(b, end=" ")