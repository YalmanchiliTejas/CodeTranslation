n = int(input())
s = str(input())
k = int(input())

object = s[k-1]
new_s = ''
for i in range(n):
    if s[i] != object:
        new_s += '*'
    else:
        new_s += s[i]

print(new_s)
