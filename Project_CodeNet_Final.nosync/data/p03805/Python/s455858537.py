from itertools import permutations

n,m=map(int,input().split())
tree=[[] for i in range(m+1)]
for i in range(m):
    a,b=map(int,input().split())
    tree[a-1].append(b-1)
    tree[b-1].append(a-1)

cnt=0
for i in permutations(range(1,n)):
    if i[0] in tree[0]:
        t_cnt=1
        for j in range(1,len(i)):
            if i[j] in tree[i[j-1]]:
                t_cnt+=1
            else:
                break
        if t_cnt==n-1:
            cnt+=1
print(cnt)