n = int(input())
s = list(input())
t = [0] * n
# 0=sheep, 1=wolf

def check(one, two):
    t[0: 2] = [one, two]
    for i in range(n - 2):
        if (s[i + 1] == "o" and t[i + 1] == 0) or (s[i + 1] == "x" and t[i + 1] == 1):
            t[i + 2] = t[i]
        else:
            t[i + 2] = 1 - t[i]
    # print(t)
    a = ((s[-1] == "o" and t[-1] == 0) or (s[-1] == "x" and t[-1] == 1)) and t[-2] == t[0]
    b = ((s[-1] == "o" and t[-1] == 1) or (s[-1] == "x" and t[-1] == 0)) and t[-2] != t[0]
    c = ((s[0] == "o" and t[0] == 0) or (s[0] == "x" and t[0] == 1)) and t[-1] == t[1]
    d = ((s[0] == "o" and t[0] == 1) or (s[0] == "x" and t[0] == 0)) and t[-1] != t[1]
    if (a or b) and (c or d):
        return t
    else:
        return None
    
def sw(t):
    ans = []
    for i in range(n):
        if t[i] == 0:
            ans.append("S")
        else:
            ans.append("W")
    return("".join(ans))

# print(check(0, 0))
# print(check(0, 1))
# print(check(1, 0))
# print(check(1, 1))
if check(0, 0) is not None:
    print(sw(check(0, 0)))
elif check(0, 1) is not None:
    print(sw(check(0, 1)))
elif check(1, 0) is not None:
    print(sw(check(1, 0)))
elif check(1, 1) is not None:
    print(sw(check(1, 1)))
else:
    print(-1)