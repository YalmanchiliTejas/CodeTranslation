N,M=list(map(int,input().split()))
color=["white"]*(N+1)
relation_list=[[] for i in range(N+1)]
count=[0]
for i in range(M):
    a,b=list(map(int,input().split()))
    relation_list[a].append(b)
    relation_list[b].append(a)

def dfs(i,j,cnt,kako):
    keiro=kako[:]
    cnt += 1
    for k in relation_list[i]:
        if k not in keiro:
            keiro.append(k)
            dfs(k,i,cnt,keiro)
            del keiro[-1]
    if cnt==N:
        count[0]+=1
dfs(1,1,0,[1])
print(count[0])


