n = int(input())
s = input()
k = int(input())

_c = s[k - 1]
_s = ""

for c in s:
    if c != _c:
        _s += "*"
    else:
        _s += c

print(_s)