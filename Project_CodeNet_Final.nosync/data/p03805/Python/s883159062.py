from itertools import permutations

N,M = list(map(int,input().split()))
P=[]
for m in range(M):
    P.append(list(map(int,input().split())))

ad={}
for _ in range(1,N+1):
    ad[_]=set()
    
for p in P:
    ad[p[0]].add(p[1])
    ad[p[1]].add(p[0])

ans=0
for p in permutations(range(2,N+1),N-1):
    ans_flag=True
    start=1
    for p_ in p:
        end=p_
#         print(start,end ,end in ad[start])
        if end not in ad[start]:
#             print('break')
            ans_flag=False
            break
        start=p_
        
    if ans_flag==True:
        ans+=1
        
print(ans)