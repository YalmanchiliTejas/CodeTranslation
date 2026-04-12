# ABC 58 C

import numpy as np

def resolve():
    n = int(input())
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    ans = {}

    for i in range(n):
        s = input()
        sdic = {}
        for a in alphabet:
            sdic[a] = 0
        for c in s:
            sdic[c] += 1

        if i == 0:
            ans = sdic
        else:
            for c in alphabet:
                ans[c] = min(ans[c], sdic[c])

    for c in alphabet:
        for i in range(ans[c]):
            print(c, end="")
    print("")


if __name__ == "__main__":
    resolve()
