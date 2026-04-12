n = int(input())
s = [input() for _ in range(n)]

apl = list("abcdefghijklmnopqrstuvwxyz")
dic = [[0 for _ in range(26)] for _ in range(n)]

for i in range(n):
    for j in range(len(s[i])):
        dic[i][apl.index(s[i][j])] += 1
result = [min([dic[i][j] for i in range(n)]) for j in range(26)]
r = ""
for i in range(26):
    r = r+apl[i]*result[i]
print(r)