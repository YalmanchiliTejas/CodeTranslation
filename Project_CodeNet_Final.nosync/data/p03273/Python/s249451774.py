h,w=map(int,input().split())
a1=[[*input()] for _ in range(h)];a2=[i for i,j in enumerate(zip(*a1)) if j.count('.')==h]
[print(*[k for l,k in enumerate(j) if l not in a2],sep='') for j in [i for i in a1 if i.count('.')<w]]