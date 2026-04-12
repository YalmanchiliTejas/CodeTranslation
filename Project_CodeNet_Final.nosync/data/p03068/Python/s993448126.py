from collections import defaultdict
from string import ascii_uppercase
import sys, bisect, math
stdin = sys.stdin
read_int = lambda : list(map(int,stdin.readline().split()))
read_str = lambda : stdin.readline().rstrip()

N = read_int()[0]
S = read_str()
K = read_int()[0]

def solve():
    ans = ""
    sk = S[K - 1]
    for i in range(N):
        if S[i] != sk:
            ans += "*"
        else:
            ans += S[i]
    return ans

if __name__ == "__main__":
    print(solve())
