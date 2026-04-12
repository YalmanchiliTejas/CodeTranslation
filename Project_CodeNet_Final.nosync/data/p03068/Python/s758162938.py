n = int(input())
s = input()
k = int(input())

t = s[k-1]
s2 = []
for i, c in enumerate(s):
    if c != t:
        s2.append("*")
    else:
        s2.append(c)
print("".join(s2))