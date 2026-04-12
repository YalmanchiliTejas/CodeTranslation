#!/usr/bin/env python3

def main():
    n = input()
    l = len(n)
    k = int(input())
    dp0 = [0 for j in range(4)]
    dp1 = [0 for j in range(4)]
    dp1[0] = 1
    for i in range(l):
        d = int(n[i])
        if d == 0:
            for j in [3, 2, 1]:
                dp0[j] += dp0[j - 1] * 9
        else:
            for j in [3, 2, 1]:
                dp0[j] += dp0[j - 1] * 9
                dp0[j] += dp1[j - 1] * max(0, d - 1)
                dp0[j] += dp1[j]
            dp0[0] += dp1[0]
            dp1 = [0] + dp1[0:3]
    print(dp0[k] + dp1[k])

if __name__ == "__main__":
    main()
