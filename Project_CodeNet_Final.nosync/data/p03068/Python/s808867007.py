n = int(input())
s = input()
k = int(input())

trig = s[k-1]

out = ""

for l in s:
    if l == trig:
        out += trig
    else:
        out += "*"

print(out)