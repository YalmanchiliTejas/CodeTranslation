n = int(input())
s = []
for _ in range(n):
    S = list(input())
    S.sort()
    s.append(S)
#print(s)
a_z = "abcdefghijklmnopqrstuvwxyz"
ans = []
for i in range(26):
    minimum = 1000000
    for j in range(n):
        kosuu = s[j].count(a_z[i])
        minimum = min(minimum, kosuu)
        if minimum == 0:
            break
    else:
        for _ in range(minimum):
            ans.append(a_z[i])
print("".join(ans))

