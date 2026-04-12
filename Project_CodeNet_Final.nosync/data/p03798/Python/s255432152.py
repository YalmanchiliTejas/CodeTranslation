from itertools import product
N=int(input())
s=input()
s = s+s

ans = None
for s0, s1 in product(range(2), repeat=2):#0:wolf, 1:sheep
    tmp = [s0, s1]
    for i in range(1, N):
        if (tmp[i] == 0 and s[i] == "o") or (tmp[i] == 1 and s[i] == "x"):
            if tmp[i-1] == 0:
                tmp.append(1)
            else:
                tmp.append(0)
        else:
            if tmp[i-1] == 0:
                tmp.append(0)
            else:
                tmp.append(1)
    if s0 == tmp[-1]:
        if (s0 == 0 and s[0] == "o") or (s0 == 1 and s[0] == "x"):
            if s1 == tmp[-2]:
                continue
        else:
            if s1 != tmp[-2]:
                continue
        ans = tmp 
        break

if ans is None:
    print(-1)
else:
    ans = ans[:-1]
    final = ""
    for a in ans:
        if a == 0:
            final += "W"
        else:
            final += "S"
    print(final)