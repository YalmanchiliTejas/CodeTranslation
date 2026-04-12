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
    [X] = [int(input_raw[0])]
    if X==7 or X==5 or X==3:
        print "YES"
    else:
        print "NO"

if __name__ == '__main__':
    main()
