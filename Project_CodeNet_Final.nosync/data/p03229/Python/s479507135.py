import sys
from collections import deque

input = sys.stdin.readline


def main():
    N = int(input())
    A = [0] * N
    for i in range(N):
        A[i] = int(input())

    A.sort()
    d = deque(A)
    min_A = d.popleft()
    max_A = d.pop()
    ans = max_A - min_A
    v1 = min_A
    v2 = max_A
    while d:
        if len(d) == 1:
            v = d.pop()
            ans += max(abs(v1 - v), abs(v2 - v))
        else:
            v_min = d[0]
            v_max = d[-1]
            diff = 0
            is_popleft = None
            if diff < abs(v1 - v_min):
                diff = abs(v1 - v_min)
                next_v1 = v_min
                next_v2 = v2
                is_popleft = True
            if diff < abs(v2 - v_min):
                diff = abs(v2 - v_min)
                next_v1 = v_min
                next_v2 = v1
                is_popleft = True
            if diff < abs(v1 - v_max):
                diff = abs(v1 - v_max)
                next_v1 = v_max
                next_v2 = v2
                is_popleft = False
            if diff < abs(v2 - v_max):
                diff = abs(v2 - v_max)
                next_v1 = v_max
                next_v2 = v1
                is_popleft = False
            if is_popleft is None:
                next_v1 = v_min
                next_v2 = v2
                is_popleft = True
            ans += diff
            v1, v2 = next_v1, next_v2
            if is_popleft:
                d.popleft()
            else:
                d.pop()

    print(ans)


if __name__ == "__main__":
    main()
