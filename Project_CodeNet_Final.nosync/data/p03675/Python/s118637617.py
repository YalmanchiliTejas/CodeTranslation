import sys
from collections import deque

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
    n = int(input_raw[0])
    input_raw = list(read_func().strip().split())
    b_list = deque([])
    is_last_first = False
    for i in range(n):
        is_last_first = not(is_last_first)
        if is_last_first == True:
            b_list.append((input_raw[i]))
        else:
            b_list.appendleft(input_raw[i])

    if is_last_first == True:
        b_list.reverse()
    print " ".join(b_list)


if __name__ == '__main__':
    main()