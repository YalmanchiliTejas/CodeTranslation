n = int(input())
s = input()
k = int(input())

r_c = s[k-1]

res = ""

for c in s:
    if c == r_c:
        res += r_c
    else:
        res += "*"
print(res)
