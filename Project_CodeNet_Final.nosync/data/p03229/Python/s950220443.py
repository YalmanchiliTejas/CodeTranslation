from collections import deque
n = int(input())
a = [int(input()) for _ in range(n)]
a.sort()
x = deque(a)
y = deque(a)


def align(a, fromLeft=1):
    if fromLeft:
        p = a.popleft()
    else:
        p = a.pop()
    q = p

    res = 0
    fromLeft = 1 - fromLeft
    while a:
        p1 = a.popleft() if fromLeft else a.pop()
        if a:
            q1 = a.popleft() if fromLeft else a.pop()
            res += abs(p - p1) + abs(q - q1)
            p = p1
            q = q1
        else:
            res += max(abs(p - p1), abs(q - p1))
        fromLeft = 1 - fromLeft
    return res


ans = max(align(x, 1), align(y, 0))
print(ans)
