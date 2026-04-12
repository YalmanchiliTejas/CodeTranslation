import sys

readline = sys.stdin.readline


def ns(): return readline().rstrip()


def ni(): return int(readline().rstrip())


def nm(): return map(int, readline().split())


def nl(): return list(map(int, readline().split()))


X = ni()
if X >= 30:
    print("Yes")
else:
    print("No")
