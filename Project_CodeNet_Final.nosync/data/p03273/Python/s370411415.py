h,w = map(int, input().split())

a = []

for i in range(h):
    s = input()
    f = 1
    for j in range(w):
        if s[j]=='#':
            f = 0
            break
    if f==0:    
        a.append(s)

out = []
for i in range(w):
    f =1
    for j in range(len(a)):
        if a[j][i] == '#':
            f = 0
            break
    if f == 1:
        out.insert(0, i)
        
        
for i in out:
    for j in range(len(a)):
        a[j] = a[j][:i]+a[j][i+1:]
            
for i in range(len(a)):
    print(a[i])
