N = int(input())
S = input()

def check(s, i, j, k):
    if j and s == "o" and i != k:
        return True
    elif j and s == "x" and i == k:
        return True
    elif not j and s == "o" and i == k:
        return True
    elif not j and s == "x" and i != k:
        return True
    return False

def func(f, s):
    l = [-1]*N
    l[0] = f
    l[1] = s
    for i in range(1, len(l) - 1):
        if l[i] and S[i] == "o" or not l[i] and S[i] == "x":
            l[i + 1] = l[i - 1] ^ 1
        else:
            l[i + 1] = l[i - 1]
    if check(S[-1], l[-2], l[-1], l[0]):
        if check(S[0], l[-1], l[0], l[1]):
            return l
    return False

for i, j in [(0, 0), (0, 1), (1, 1), (1, 0)]:
    l = func(i, j)
    if l:
        for v in l:
            print("SW"[v], end="")
        print()
        exit()
print(-1)