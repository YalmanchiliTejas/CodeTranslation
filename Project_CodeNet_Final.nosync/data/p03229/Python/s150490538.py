import sys
from collections import deque

input = sys.stdin.readline


def main():
    N = int(input())
    A = [0] * N
    for i in range(N):
        A[i] = int(input())

    A.sort()
    ans = 0
    if N % 2 == 1:
        # center is minimum
        a = deque(A[1:])
        b = deque([A[0]])
        nxt = "r"
        while a:
            if nxt == "r":
                nxt = "l"
                x = a.pop()
                y = a.pop()
                b.appendleft(x)
                b.append(y)
            else:
                nxt = "r"
                x = a.popleft()
                y = a.popleft()
                b.appendleft(x)
                b.append(y)
        diff = sum(abs(b[i + 1] - b[i]) for i in range(N - 1))
        ans = max(ans, diff)
        # center is maximum
        a = deque(A[::-1][1:])
        b = deque([A[-1]])
        nxt = "r"
        while a:
            if nxt == "r":
                nxt = "l"
                x = a.pop()
                y = a.pop()
                b.appendleft(x)
                b.append(y)
            else:
                nxt = "r"
                x = a.popleft()
                y = a.popleft()
                b.appendleft(x)
                b.append(y)
        diff = sum(abs(b[i + 1] - b[i]) for i in range(N - 1))
        ans = max(ans, diff)

    else:
        # center is minimum
        a = deque(A[1:])
        b = deque([A[0]])
        nxt = "r"
        while a:
            if len(a) == 1:
                rem = a.pop()
                break
            if nxt == "r":
                nxt = "l"
                x = a.pop()
                y = a.pop()
                b.appendleft(x)
                b.append(y)
            else:
                nxt = "r"
                x = a.popleft()
                y = a.popleft()
                b.appendleft(x)
                b.append(y)
        diff = sum(abs(b[i + 1] - b[i]) for i in range(N - 2))
        diff += max(abs(rem - b[0]), abs(rem - b[-1]))
        ans = max(ans, diff)

        # center is maximum
        a = deque(A[::-1][1:])
        b = deque([A[-1]])
        nxt = "r"
        while a:
            if len(a) == 1:
                rem = a.pop()
                break
            if nxt == "r":
                nxt = "l"
                x = a.pop()
                y = a.pop()
                b.appendleft(x)
                b.append(y)
            else:
                nxt = "r"
                x = a.popleft()
                y = a.popleft()
                b.appendleft(x)
                b.append(y)
        diff = sum(abs(b[i + 1] - b[i]) for i in range(N - 2))
        diff += max(abs(rem - b[0]), abs(rem - b[-1]))
        ans = max(ans, diff)

    print(ans)


if __name__ == "__main__":
    main()
