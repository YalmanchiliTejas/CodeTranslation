def examA():
    c = S()
    v = ["a", "i", "u", "e", "o"]
    ans = "consonant"
    if c in v:
        ans = "vowel"
    print(ans)

import sys
def I(): return int(sys.stdin.readline())
def LI(): return list(map(int,sys.stdin.readline().split()))
def LS(): return sys.stdin.readline().split()
def S(): return sys.stdin.readline().strip()
mod = 10**9 + 7
inf = float('inf')

examA()