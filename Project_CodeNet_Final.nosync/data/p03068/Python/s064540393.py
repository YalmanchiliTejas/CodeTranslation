n = int(input())
s = list(input())
k = int(input())

# print(list(s))
t = str()
for i in range(n):
    if s[i] == s[k-1]:
        pass
    else:
        s[i] = '*'
    t += s[i]

print(t)
