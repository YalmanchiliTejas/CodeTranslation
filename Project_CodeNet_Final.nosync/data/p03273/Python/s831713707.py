import sys
import numpy as np


stdin = sys.stdin
def ns(): return stdin.readline().rstrip()
def ni(): return int(stdin.readline().rstrip())
def nm(): return map(int, stdin.readline().split())
def nl(): return list(map(int, stdin.readline().split()))


def main():
    h, w = nm()
    A = np.array([list(ns()) for _ in range(h)])
    i = 0
    while i < len(A):
        if np.all(A[i] == '.'):
            A = np.delete(A, i, 0)
        else:
            i += 1

    j = 0
    while j < len(A[0]):
        if np.all(A[:, j] == '.'):
            A = np.delete(A, j, 1)
        else:
            j += 1
    for a in A:
        print(''.join(a))


if __name__ == '__main__':
    main()
