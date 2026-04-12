from itertools import permutations

n,m = map(int,input().split())
t = []
for _ in range(m):
    a,b = map(int,input().split())
    t.append([a, b])
    t.append([b, a])
l = [i for i in range(2,n+1)]
p = permutations(l)
cnt = 0
for v in p:
    if [1, v[0]] not in t:
        continue
    for i in range(n-2):
        if [v[i], v[i+1]] in t:
            continue
        else:
            break
    else:
        cnt += 1
print(cnt)
