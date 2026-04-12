h ,w = map(int,input().split())
p = []
cou = 0

for i in range(h):
    s = list(input())
    if s.count("#") != 0:
        p.append(s)
        cou += 1

q = {i for i in range(w)}

for i in range(cou):
    kar = set()
    for j in range(w):
        if p[i][j] == ".":
            kar.add(j)
    q = q & kar
    
s = {i for i in range(w)}
s = s - q
    
for i in range(cou):
    for j in s:
        print(p[i][j],end="")
    print()