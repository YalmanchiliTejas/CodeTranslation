h, w = map(int, input().split())
s = []

for i in range(h):
    a = input()
    s.append([str(m) for m in list(str(a))])

coi = 0
p = len(s)
for i in range(h):
    i = i - coi
    """if i > len(s) - 1 - coi:
        break"""
    #for j in range(w):
    if "#" not in s[i]:
        s.pop(i)
        p = len(s)
        coi += 1

coj = 0
for j in range(w):
    j = j - coj
    for i in range(len(s)):
        """if j > len(s[0]) - 1 - coj:
            break"""
        if "#" == s[i][j]:
            break
        if "." == s[i][j] and i == len(s) - 1:
            for m in range(len(s)):
                s[m].pop(j)
            coj += 1

t = []

for i in range(len(s)):
    t.append( ''.join(s[i]))

for i in range(len(t)):
    print(t[i])