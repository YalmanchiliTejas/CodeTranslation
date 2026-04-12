H, W = map(int, input().split())
a = [input() for i in range(H)]
b = []
for i in range(H):
    if '#' in a[i]:
        b.append(a[i])
        
ans = zip(*[i for i in zip(*b) if '#' in i])
 
for j in ans:
    print(*j, sep='')