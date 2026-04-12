# ARC077C - pushpush (ABC066C)
from collections import deque


def main():
    n = int(input())
    lst = list(map(int, input().rstrip().split()))
    b = deque()
    parity = n % 2
    for i, j in enumerate(lst, start=1):
        if i % 2 == parity:
            b.appendleft(j)
        else:
            b.append(j)
    print(*b)


if __name__ == "__main__":
    main()