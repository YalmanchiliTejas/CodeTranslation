#!/usr/bin/env python3

from copy import deepcopy

def main():
    n = input()
    l = len(n)
    k = int(input())
    dp0 = [0 for j in range(4)]
    dp1 = [0 for j in range(4)]
    dp1[0] = 1
    for i in range(l):
        dppre0 = deepcopy(dp0)
        dppre1 = deepcopy(dp1)
        d = int(n[i])
        if d == 0:
            for j in [1, 2, 3]:
                dp0[j] += dppre0[j - 1] * 9
        else:
            for j in [1, 2, 3]:
                dp0[j] += dppre0[j - 1] * 9
                dp0[j] += dppre1[j - 1] * max(0, d - 1)
            for j in [0, 1, 2, 3]:
                dp0[j] += dppre1[j]
            dp1 = [0 for j in range(4)]
            for j in [1, 2, 3]:
                dp1[j] = dppre1[j - 1]
    print(dp0[k] + dp1[k])

if __name__ == "__main__":
    main()
