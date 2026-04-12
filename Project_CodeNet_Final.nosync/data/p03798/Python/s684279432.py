import sys


def calc(s, x, i):
    if s[i] == "S":
        if x == "o":
            return s[i-1]
        elif s[i-1] == "S":
            return "W"
        else:
            return "S"
    else:
        if x == "x":
            return s[i-1]
        elif s[i-1] == "S":
            return "W"
        else:
            return "S"


n = int(input())
s = input()
for s1 in ["S", "W"]:
    for sn in ["S", "W"]:
        ans = [s1] + [""] * (n-2) + [sn]
        for i in range(n-1):
            ans[i+1] = calc(ans, s[i], i)
        zn = calc(ans, s[-2], n-2)
        z1 = calc(ans, s[-1], n-1)
        if zn == sn and z1 == s1:
            print("".join(ans))
            sys.exit()

print(-1)
