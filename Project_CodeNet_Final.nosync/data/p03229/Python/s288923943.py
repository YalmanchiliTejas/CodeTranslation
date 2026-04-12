n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
a.sort()
b = []
d = []
for i in range(n):
    c = i // 2
    if i%2 == 0:
        b.append(a[c])
    else:
        b.append(a[n-1-c])
        
for i in range(n):
    c = i // 2
    if i%2 == 1:
        d.append(a[c])
    else:
        d.append(a[n-1-c])
        
b.append(a[0])
d.append(a[n-1])
sa = []
sa2 = []
for i in range(n):
    sa.append(abs(b[i+1] - b[i]))
    sa2.append(abs(d[i+1] - d[i]))
    
print(max(sum(sa) - min(sa) , sum(sa2) - min(sa2)))