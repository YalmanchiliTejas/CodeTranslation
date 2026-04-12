import  itertools

N,M=map(int,input().split())
graph = [[] for _ in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

def judge(pattern):
    if pattern[0]!=0:
        return False
    else:
        flag=True
        for i in range(len(pattern)-1):
            if pattern[i+1] in graph[pattern[i]]:
                continue
            else:
                flag=False
        if flag:
            return True
        return False

nums=[]
for i in range(N):
    nums.append(i)
ans=0
for pa in itertools.permutations(nums,N):
    pas=list(pa)
    if judge(pas):
        ans+=1

print(ans)