N = int(input())

if N%2==1:
    print("First")
    exit()
elif N==2:
    print("Second")
    exit()

E = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    E[a].append(b)
    E[b].append(a)

E_dim = [len(e) for e in E]
E_set = [set(e) for e in E]
q = []
for v, (dim, e) in enumerate(zip(E_dim, E)):
    if dim==1:
        for u in e:
            if E_dim[u] == 2:
                q.append(v)
                
while q:
    v = q.pop()
    u = E_set[v].pop()
    if E_dim[u] == 1:
        print("Second")
        exit()
    E_set[u].remove(v)
    w = E_set[u].pop()
    E_set[w].remove(u)
    E_dim[w] -= 1
    if E_dim[w] == 1:
        x = E_set[w].copy().pop()
        if E_dim[x] == 2:
            q.append(w)
    elif E_dim[w] == 2:
        for x in E_set[w]:
            if E_dim[x] == 1:
                q.append(x)
print("First")

