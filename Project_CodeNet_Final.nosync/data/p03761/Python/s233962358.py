# C - 怪文書 / Dubious Document

n = int(input())
S = [input() for _ in range(n)]

alf = [[] for _ in range(26)]

for string in S:
    tmp = [0]*26
    for letter in string:
        tmp[ord(letter) - 97] += 1
    for al in range(26):
        alf[al].append(tmp[al])

alf = [min(x) for x in alf]
ans = ""
for al in range(26):
    ans += chr(al+97) * alf[al]
    
print(ans)