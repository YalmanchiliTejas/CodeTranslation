import sys
from collections import deque
import copy
import math
def get_read_func(fileobject):
    if fileobject == None :
        return raw_input
    else:
        return fileobject.readline

def print_and_exit(X, eated_P):
    if X == 0:
        print eated_P
        exit()

table = {}

def get_burger_size(L):
    global table
    if L in table:
        return table[L]
    if L == 0:
        table[0] = (1L, 1L)
        return (1L, 1L)

    l_1_burger = get_burger_size(L - 1)
    table[L - 1] = l_1_burger
    return  (3L + 2L * l_1_burger[0], 1L + 2L * l_1_burger[1])

g_eated = 0
g_eated_P = 0

def calc_eated(X, L, eated_P):
    X -= 1
    print_and_exit(X, eated_P)

    (eated_f, eated_P_f) = get_burger_size(L - 1)
    if X < eated_f:
        calc_eated(X, L - 1, eated_P)
    X -= eated_f
    eated_P += eated_P_f
    print_and_exit(X, eated_P)

    eated_P += 1
    X -= 1
    print_and_exit(X, eated_P)

    (eated_f, eated_P_f) = get_burger_size(L - 1)
    if X < eated_f:
        calc_eated(X, L - 1, eated_P)
    X -= eated_f
    eated_P += eated_P_f
    print_and_exit(X, eated_P)

    X -= 1
    print_and_exit(X, eated_P)



def main():
    if len(sys.argv) > 1:
        f = open(sys.argv[1])
    else:
        f = None
    read_func = get_read_func(f);
    input_raw = read_func().strip().split()
    [N, X] = [long(input_raw[0]), long(input_raw[1])]
    calc_eated(X, N, 0)


if __name__ == '__main__':
    main()
