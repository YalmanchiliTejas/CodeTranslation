import sys
from math import ceil, floor
from collections import deque, Counter, defaultdict
from fractions import gcd
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return

def main():
    s = input()
    a = False
    b = False
    for i in range(3):
        if s[i] == 'A':
            a = True
        if s[i] == 'B':
            b = True
    if a and b:
        print('Yes')
    else:
        print('No')
    
    return

if __name__ == '__main__':
    main()