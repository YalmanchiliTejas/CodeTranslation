from itertools import permutations
n, m = map(int, input().split())

ab=[[] for _ in range(n)]#１から順にどの頂点からどの頂点に辺が続いているか
for i in range(m):
    a,b=map(int,input().split())
    ab[a-1].append(b-1)
    ab[b-1].append(a-1)

#print(ab)

l=list(range(1,n))
p = list(permutations(l, n - 1))#頂点をたどる順番。Nの階乗

ans=0
for i in p:
#    print(p)
    flg=0
    if i[0] not in ab[0]:
        continue   
    for j in range(n-2):
        if i[j+1] in ab[i[j]]:
            continue
        else:
            flg=1
            break
    if flg==0:
        ans+=1
print(ans)