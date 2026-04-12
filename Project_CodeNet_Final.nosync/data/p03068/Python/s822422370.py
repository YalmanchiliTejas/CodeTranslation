n = int(input())
s = input()
k = int(input())

e = s[k-1]

res = ''
for c in s:
    if c != e:
        res += '*'
    else:
        res += e

print(res)