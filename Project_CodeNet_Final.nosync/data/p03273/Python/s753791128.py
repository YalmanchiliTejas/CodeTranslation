h,w = map(int,input().split())
a = [list(input()) for _ in range(h)]

b = []
for i in range(h):
    cnt = 0
    for j in range(w):
        if a[i][j] == '.':
            cnt += 1
            
    if cnt != w:
        b.append(a[i])

c = ['']*len(b) 
for i in range(len(b[0])):
    cnt = 0
    for j in range(len(b)):
        if b[j][i] == '.':
            cnt += 1
    
    if cnt != len(b):
        for j in range(len(b)):
            c[j] += b[j][i]

for i in range(len(c)):
    print(c[i])