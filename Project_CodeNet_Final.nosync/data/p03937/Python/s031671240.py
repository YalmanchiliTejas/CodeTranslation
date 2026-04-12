import sys
from collections import deque
import copy
import math
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
        input_raw = read_func().strip()
        field.append(input_raw)

    pre_last = -1
    for i in range(H):
        first = -1
        last = -1
        for j in range(W):
            if field[i][j] == '#':
                if first == -1:
                    first = j
                last = j
        if pre_last > first:
            print "Impossible"
            return
        pre_last = last

    pre_last = -1
    for j in range(W):
        first = -1
        last = -1
        for i in range(H):
            if field[i][j] == '#':
                if first == -1:
                    first = j
                last = j
        if pre_last > first:
            print "Impossible"
            return
        pre_last = last

    print "Possible"

if __name__ == '__main__':
    main()