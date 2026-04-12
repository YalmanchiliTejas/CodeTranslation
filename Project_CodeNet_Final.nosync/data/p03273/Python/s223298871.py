h, w = map(int, input().split())
A = [input() for _ in range(h)]

A = [A[i] for i in range(h) if any(x == '#' for x in A[i])] 
h = len(A)
ans = [[] for i in range(h)]
for i in range(w):
    if any(x[i] == '#' for x in A):
        for j, x in enumerate(A):
            ans[j].append(x[i])
print(*[''.join(row) for row in ans], sep='\n')
