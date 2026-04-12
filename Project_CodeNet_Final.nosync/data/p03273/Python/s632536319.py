import sys

H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(list(input()))

#行削除
for line in a[:]:
    if line.count('.') == len(line):
        a.remove(line)

if len(a)==0:
    sys.exit

b = []

#転地
for row in range(len(a[0])):
    tmp = []
    for line in range(len(a)):
        tmp.append(a[line][row])
    b.append(tmp)    

for line in b[:]:
    if line.count('.') == len(line):
        b.remove(line)
c=[]
#転地
for row in range(len(b[0])):
    tmp = []
    for line in range(len(b)):
        tmp.append(b[line][row])
    c.append(tmp)    


for row in c:
    print(''.join(row))
        
    
        
    
