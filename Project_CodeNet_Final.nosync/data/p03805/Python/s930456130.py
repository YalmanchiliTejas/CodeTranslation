from itertools import permutations
N,M = map(int,input().split())
table=[[]for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    table[a-1].append(b-1)
    table[b-1].append(a-1)

def f(L,k):
    for a in L:
        if a==k:
            return True
    return False

S=[i for i in range(1,N)]
ans =0
for s in permutations(S,N-1):
    flag =True
    if not f(table[0],s[0]):
        continue
    for i in range(N-2):
        if not f(table[s[i]],s[i+1]):
            flag =False
    if flag:
        ans+=1
print(ans)