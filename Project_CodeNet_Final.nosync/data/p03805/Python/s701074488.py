from itertools import permutations
n,m = map(int,input().split())

rel_t = [[False for i in range(n)] for j in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    rel_t[a-1][b-1]=True
    rel_t[b-1][a-1]=True

cnt=0
n_list = [i for i in range(n)]
for l in permutations(n_list,len(n_list)):
    if(l[0]!=0):
        continue
    judge=[rel_t[l[i]][l[i+1]] for i in range(n-1)]
    if all(judge):
        cnt+=1

print(cnt)