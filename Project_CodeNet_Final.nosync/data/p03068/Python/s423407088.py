n = int(input())
s = input()
k = int(input())

letter = s[k-1]
out = ''

for i in range(n):
    if s[i] == letter:
        out += s[i]
    else:
        out += '*'

print(out)