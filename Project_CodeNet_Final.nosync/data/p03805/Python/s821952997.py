# -*- coding: utf-8 -*-
import numpy as np

def saiki(matrix, fin_l, pos, count):
    for i in range(N):
        move = int(matrix[i, pos])
        if move == 1 and i!=pos and fin_l[i]==0:
            next_pos = i
            fin_l[i] = 1
            if 0 not in fin_l:
                count += 1
                fin_l[i] = 0
                continue
            count = saiki(matrix, fin_l, next_pos, count)
            fin_l[i] = 0

    return count

if __name__ == '__main__':


    N, M = map(int, input().split(' '))
    matrix = np.zeros((N, N))

    for i in range(M):
        a, b = map(int, input().split(' '))
        matrix[a-1, b-1] = 1
        matrix[b-1, a-1] = 1

    for i in range(N):
        matrix[i, i] = 1

    # 訪問済み 配列
    fin_l = [1]
    fin_l.extend([0]*(N-1))
    count = 0
    count = saiki(matrix, fin_l, 0, count)

    print(count)