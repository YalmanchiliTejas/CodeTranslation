h,w = map(int,input().split())

f = []

for i in range(h):
    f.append(list(input()))
    
a = []
    
for i in range(len(f)):
    if f[i] == ["."]*len(f[i]):
        a.append(i)
        
for i in a:
    del f[i]
    for s in range(len(a)):
        a[s] -= 1
        
f2 = []

for i in range(w):
    s = []
    
    for k in f:
        s.append(k[i])
        
    f2.append(s)
    
b = []
    
for i in range(len(f2)):
    if f2[i] == ["."]*len(f2[i]):
        b.append(i)
        
for i in b:
    del f2[i]
    for s in range(len(b)):
        b[s] -= 1
        
ff = []

for i in range(len(f2[0])):
    s = []
    
    for k in f2:
        s.append(k[i])
        
    ff.append(s)
        
for i in ff:
    for s in range(len(i)-1):
        print(i[s],end = "")
    
    print(i[-1])