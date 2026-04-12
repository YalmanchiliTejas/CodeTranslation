import sys
from collections import deque
import copy

from math import *

def get_read_func(fileobject):
    if fileobject == None :
        return raw_input
    else:
        return fileobject.readline

def main():
    if len(sys.argv) > 1:
        f = open(sys.argv[1])
    else:
        f = None
    read_func = get_read_func(f);
    input_raw = read_func().strip().split()
    [H, W] = [int(input_raw[0]), int(input_raw[1])]
    field = []
    for i in range(H):
        input_raw = read_func().strip().split()
        field.append(input_raw[0])
    is_all_white_raw = [True for i in range(H)]
    is_all_white_col = [True for i in range(W)]

    for i in range(H):
        for j in range(W):
            if field[i][j] == "#":
                is_all_white_raw[i] = False
                break

    for j in range(W):
        for i in range(H):
            if field[i][j] == "#":
                is_all_white_col[j] = False
                break

    for i in range(H):
        if is_all_white_raw[i] == True:
            continue
        for j in range(W):
            if is_all_white_col[j] == True:
                continue
            sys.stdout.write(field[i][j])
        print

if __name__ == '__main__':
    main()