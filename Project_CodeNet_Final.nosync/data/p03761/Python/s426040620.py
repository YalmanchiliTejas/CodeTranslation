import collections

import numpy as np


def main():
    N = int(input())
    S = [list(input()) for _ in range(N)]

    A = np.zeros([N, 26], dtype=np.int32)

    for i in range(N):
        for s in S[i]:
            c = int(ord(s) - ord('a'))
            A[i, c] += 1

    B = np.min(A, axis=0)

    ans = []
    for c in range(26):
        for i in range(B[c]):
            ans.append(chr(c + ord('a')))

    print(''.join(ans))


main()
