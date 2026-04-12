n = int(input())
sl = list(input() for _ in range(n))
alf = "abcdefghijklmnopqrstuvwxyz"
alfl =[51]*26

for i in range(26):
    for j in range(n):
        t = sl[j].count(alf[i])
        alfl[i] = min(t,alfl[i])

res = ""

for k in range(26):
    res += alf[k]*alfl[k]
print(res)