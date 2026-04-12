import sys
import numpy as np
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
    rgb = int(input_raw[0])*100 + int(input_raw[1]) *10 + int(input_raw[2])
    if rgb % 4 == 0 :
        print 'YES'
    else:
        print 'NO'

if __name__ == '__main__':
    main()