import itertools as it
n,m = map(int, input().split())
keiro = []
for i in range(m):
    a,b = map(int, input().split())
    keiro.append([a,b])
per = it.permutations(range(2,n+1),n-1)
ans = 0
for pe in per:
    Flag = True
    pe = list(pe)
    pe.insert(0,1)
    for i in range(len(pe)-1):
        if [pe[i],pe[i+1]] not in keiro and [pe[i+1],pe[i]] not in keiro:
            Flag = False
            break
    if Flag == True:
        ans +=1
print(ans)