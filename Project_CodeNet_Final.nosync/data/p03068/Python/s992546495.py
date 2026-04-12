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
    S = input_raw[0]
    input_raw = read_func().strip().split()
    [K] = [int(input_raw[0])]
    s = S[K - 1]
    new_S = ""
    for i in range(N):
        if S[i] != s:
            new_S += "*"
        else:
            new_S += S[i]
    print new_S


if __name__ == '__main__':
    main()
