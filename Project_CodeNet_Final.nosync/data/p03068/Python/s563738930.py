n = int(input())
s = list(input())
k = int(input())

rep = s[k-1]
s = [x if x == rep else "*" for x in s]

print("".join(s))