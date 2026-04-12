n = int(input())

S = []
for i in range(n):
    S.append(input())
    
cnt = [50] * 26

for i in range(n):
    tmp = [0] * 26
    for j in range(len(S[i])):
        tmp[ord(S[i][j])-97] += 1
    for j in range(26):
        cnt[j] = min(cnt[j],tmp[j])

res = '' 
for i in range(26):
    for j in range(cnt[i]):
        res = res + chr(97 + i)

print(res)