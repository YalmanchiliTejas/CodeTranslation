import sys
input = sys.stdin.readline


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()

    import collections
    q = collections.deque(A)

    p = collections.deque()
    p.append(q.pop())
    ans = 0
    while q:
        q1, q2 = q[0], q[-1]
        p1, p2 = p[0], p[-1]
        a = abs(q1 - p1)
        b = abs(q1 - p2)
        c = abs(q2 - p1)
        d = abs(q2 - p2)
        ma = max(a, b, c, d)
        ans += ma
        if ma == a:
            p.appendleft(q.popleft())
        elif ma == b:
            p.append(q.popleft())
        elif ma == c:
            p.appendleft(q.pop())
        elif ma == d:
            p.append(q.pop())
    print(ans)


if __name__ == '__main__':
    main()
