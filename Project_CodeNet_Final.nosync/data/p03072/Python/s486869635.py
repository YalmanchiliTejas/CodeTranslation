from collections import defaultdict
from string import ascii_uppercase
import sys, bisect, math
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

N = read_int()[0]
H = read_int()

def solve():
    ans = 1
    mh = H[0]
    for i in range(1, N):
        cansee = True
        for j in range(0, i):
            if H[j] > H[i]:
                cansee = False
                break
        if cansee:
            ans += 1
    return ans

if __name__ == "__main__":
    print(solve())
