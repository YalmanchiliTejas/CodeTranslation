n = int(raw_input())
s = raw_input()
k = int(raw_input())

l = list(s)
t = l[k-1]
a = ''

for i in l:
    if i == t:
        a += t
    else:
        a += "*"

print a