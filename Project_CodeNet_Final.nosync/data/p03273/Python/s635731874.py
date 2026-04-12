#!/usr/bin/env python3
import numpy as np

def main():
    H,W = map(int,input().split())
    a = [list(input()) for _ in range(H)]

    ok_i = []
    ok_j = []
    for i in range(H):
        for j in range(W):
            if a[i][j] == '#':
                ok_i.append(i)
                break

    for i in range(W):
        for j in range(H):
            if a[j][i] == '#':
                ok_j.append(i)
                break

    answer = []

    b = [aa for idx, aa in enumerate(a) if idx in ok_i]
    for i in range(len(b)):
        temp = []
        for j in range(W):
            if j in ok_j:
                temp.append(b[i][j])
        answer.append(temp)
    
    for i in range(len(answer)):

        print(''.join(answer[i]))





if __name__ == '__main__':
    main()
