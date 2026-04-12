

N,M = map(int,raw_input().split())

edge= [[] for i in range(N)]

for i in range(M):
    a,b = map(int,raw_input().split())
    edge[a-1].append(b)
    edge[b-1].append(a)

def search(v,edge,cl,count):
    come_list = cl[:]
    come_list[v-1]=1
    if sum(come_list)==N:
         return count+1
    else:
        for e in edge[v-1]:
            if come_list[e-1]==0:
                count=search(e,edge,come_list,count)
    return count
            
cl = [0 for i in range(N)]
print search(1,edge,cl,0)