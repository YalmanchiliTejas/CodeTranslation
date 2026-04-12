import sys
import numpy as np

def LI(): return [int(x) for x in sys.stdin.readline().split()]


if __name__ == "__main__":
    h, w = LI()
    a = []
    for _ in range(h):
        row = input()
        if row == '.'*w:
            continue
        else:
            a.append([e for e in row])

    b = []
    a_ = np.array(a).T
    for row in a_:
        if list(row) == ['.']*len(a):
            continue
        else:
            b.append(row)

    b = np.array(b).T
    for row in b:
        print(''.join(row))
