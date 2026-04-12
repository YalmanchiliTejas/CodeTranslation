# -*- coding: utf-8 -*-
import numpy as np

def solve():
    H, W = map(int, input().split())
    M = np.array([list(input())])
    for h in range(H-1):
        M = np.vstack((M,np.array([list(input())])))

    h = np.where(~(M == '.').all(axis=1))[0]
    v = np.where(~(M == '.').all(axis=0))[0]
    M = M[h,:][:,v]

    return '\n'.join([''.join([b for b in a]) for a in M])

if __name__ == '__main__':
    print(solve())