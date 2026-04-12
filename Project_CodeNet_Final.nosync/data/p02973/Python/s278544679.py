from collections import deque
import bisect
import sys
sys.setrecursionlimit(10**9)


def main():
    N = int(input())
    X = deque()

    for _ in range(N):
        a = int(input())
        j = bisect.bisect_left(X,a)

        if j == 0:
            X.appendleft(a)
        else:
            X[j-1] = a


    print(len(X))


if __name__ == "__main__":
  main()
