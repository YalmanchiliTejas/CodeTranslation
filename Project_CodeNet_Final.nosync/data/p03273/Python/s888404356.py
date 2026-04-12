H,W = map(int, input().split())
row = []
erase = []
for i in range(H):
    r = list(input())
    count = 0
    for j in range(W):
        if r[j] == '.':
            count += 1
    if count != W:
        row.append(r)        

for k in range(W): 
    count2 = 0
    for l in range(len(row)): 
        if row[l][k] == '.':
            count2 += 1
    if count2 == len(row):
        erase.append(k)

answer = []
if len(erase) > 0:
    for m in range(len(row)):
        ans = ''
        for n in range(len(row[m])):
            if n not in erase:
                ans += row[m][n]
        answer.append(ans)
    
else:
    for p in range(len(row)):
        ans = ''
        for q in range(len(row[p])):
            ans += row[p][q]
        answer.append(ans)
    

for o in answer:
    print(o)
