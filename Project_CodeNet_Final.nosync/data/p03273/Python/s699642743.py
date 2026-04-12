import numpy as np
if __name__ == '__main__':
    H, W = map(int, input().split())
    A = [None]*H
    row = [False]*H
    col = [False]*W
    for i in range(H):
        A[i] = str(input())
        for j in range(W):
            if A[i][j] == '#':
                row[i] = True
                col[j] = True
    for i in range(H):
        if row[i]:
            for j in range(W):
                if col[j]:
                    print(A[i][j], end='')
            print()