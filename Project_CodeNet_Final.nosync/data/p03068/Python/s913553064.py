n = int(input())
s = input()
k = int(input())
sa = s[k - 1: k]
sl = len(s)
sli = list(s)
hey = []
for sli in sli:
    if sli == sa:
        hey.append(sli)
    else:
        hey.append("*")
hey = "".join(hey)
print(hey)
