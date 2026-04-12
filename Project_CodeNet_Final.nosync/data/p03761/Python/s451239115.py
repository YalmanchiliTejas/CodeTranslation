n = int(input())
S = []
for i in range(n):
    s = list(input())
    S.append(s)
ans = []
first = list(S[0])

for i in range(len(first)):
    flag = True
    for j in range(1,n):
        if first[i] not in S[j]:
            flag = False
    if flag:
        ans.append(first[i])
        for h in range(1,n):
            S[h].remove(first[i])
ans.sort()
print(''.join(ans))