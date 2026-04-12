from collections import deque

N = int(input())
a = [int(input()) for _ in range(N)]

a.sort()
def calc(m):
    if m == 1:
        dqa = deque(a[1:])
        dq = deque([a[0]])
        cnt = 0
    else: 
        dqa = deque(a[:N-1])
        dq = deque([a[-1]])
        cnt = 2

    while len(dq) < N:
        if cnt == 0:
            q = dqa.pop()
            dq.append(q)
        elif cnt == 1:
            q = dqa.pop()
            dq.appendleft(q)
        elif cnt == 2:
            q = dqa.popleft()
            dq.append(q)
        else:
            q = dqa.popleft()
            dq.appendleft(q)
            cnt = -1
        cnt += 1

    ans = 0
    for i in range(1, N):
        ans += abs(dq[i] - dq[i-1])
    return ans
        
print(max(calc(0), calc(1)))
