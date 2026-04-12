n = int(input())
di = [[0]*123 for _ in range(n)]
new = [0]*123
al = []
for i in range(n):
    s = str(input())
    for j in range(len(s)):
        p = ord(s[j])
        di[i][p] += 1
for k in range(97,123):
    a = float("inf")
    for l in range(n):
        if a > di[l][k]:
            a = di[l][k]
    new[k] = a
for m in range(97,123):
    if new[m] != 0:
        st = chr(m)
        al += [st]*(new[m])
if al != []:
    print("".join(al))
else:
    print("")