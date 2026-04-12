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
    [N] = [int(input_raw[0])]
    input_raw = read_func().strip().split()
    count = 0
    max_H = 0
    H = [int(input_raw[i]) for i in range(N)]
    for i in range(N):
        if H[i] >= max_H:
            count += 1
            max_H = H[i]
    print count


if __name__ == '__main__':
    main()
