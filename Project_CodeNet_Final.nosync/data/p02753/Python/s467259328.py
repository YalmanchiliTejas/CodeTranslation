from collections import defaultdict
from collections import deque
from string import ascii_uppercase
import sys, bisect, math, heapq

stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

S = read_str()

def solve():
    if S == 'AAA' or S == 'BBB':
        return 'No'
    return 'Yes'

if __name__ == "__main__":
    print(solve())