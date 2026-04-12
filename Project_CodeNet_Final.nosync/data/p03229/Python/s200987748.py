from collections import deque

def solve(n, a):
    a = sorted(a)
    return max(f(n, a), f(n, a[::-1]))

def f(n, a):
    a = deque(a)
    b = deque([])
    for i in range(n):
        if (i-1) % 4 < 2:
            v = a.popleft()
        else:
            v = a.pop()
        if i % 2 == 0:
            b.appendleft(v)
        else:
            b.append(v)
    return sum([abs(b[i+1]-b[i]) for i in range(n-1)])

n = int(input())
a = [int(input()) for i in range(n)]
print(solve(n, a))