import math
import collections
import fractions
import itertools

def solve():
    n = int(input())
    s = list(input())
    k= int(input())
    tar = s[k-1]
    for i in range(n):
        if tar != s[i]:
            s[i] = "*"
    print("".join(s))
    return 0

if __name__ == "__main__":
    solve()