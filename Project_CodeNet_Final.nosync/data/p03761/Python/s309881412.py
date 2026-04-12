n = int(input())
s = list(input())
for i in range(n - 1):
    s1 = list(input())
    s2 = []
    for j in s1:
        if j in s:
            s2.append(s.pop(s.index(j)))
    s = s2
s.sort()
print("".join(s))