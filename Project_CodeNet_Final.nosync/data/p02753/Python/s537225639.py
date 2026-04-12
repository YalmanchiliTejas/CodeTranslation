import sys
from math import *
from collections import deque, Counter, defaultdict
from fractions import gcd
input = lambda: sys.stdin.readline().rstrip()

def eprint(s):
    sys.stderr.write('DEBUG: {}'.format(s))
    return

def main():
    ans="Yes"
    S = input()
    if(S=='AAA' or S=='BBB'):
      ans="No"
    print(ans)
    return

if __name__ == '__main__':
    main()