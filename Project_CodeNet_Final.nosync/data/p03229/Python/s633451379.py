import sys
from collections import deque
import copy

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')


def calc(N, A, max_min):

    if max_min:
        al = deque([A.popleft()])
        f = True
    else:
        al = deque([A.pop()])
        f = False

    while A:
        if len(A) >= 2:
            if f:
                al.append(A.pop())
                al.appendleft(A.pop())
                f = False
            else:
                al.appendleft(A.popleft())
                al.append(A.popleft())
                f = True

        elif len(A) == 1:
            al.append(A.pop())

    ans = 0
    for i in range(N - 1):
        ans += abs(al[i + 1] - al[i])

    return ans


def main():
    N = in_n()
    A = deque(sorted(list(in_na())))

    ans1 = calc(N, copy.copy(A), True)
    ans2 = calc(N, copy.copy(A), False)
    print(max(ans1, ans2))


if __name__ == '__main__':
    main()
