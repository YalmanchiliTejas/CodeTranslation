N, M=(int(i) for i in input().split())
P=[]
for i in range(M):
    P.append([int(i) for i in input().split()])


ans=0
q=[]
s=1

def func(s,Q,r):
    global ans
    for q ,P in Q:
        if r==N-1:
            ans+=1
        n_s=[i for i in q if i!=s][0]
        n_q=[]
        for p in P:
            if n_s in p:
                n_q.append([p, [_p for _p in P if n_s not in _p]])
        if len(n_q)==0:
            continue
        else:
            func(n_s, n_q, r+1)


for p in P:
    if s in p:
        q.append([p, [_p for _p in P if s not in _p]])
func(s,q,1)
print(ans)