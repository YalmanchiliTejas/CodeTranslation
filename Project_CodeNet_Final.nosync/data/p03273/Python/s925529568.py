h,w=map(int, input().split())
s=[list(input()) for i in range(h)] 
x=0
v=0
count=0
for i in range(h):
    if s[x].count('.')==w:
        del s[x] 
    else:
        x+=1
for j in range(w):
    for i in range(len(s)):
        if s[i][v]=='.':
            count+=1
    if count==len(s):
        count=0
        for i in range(len(s)):
            del s[i][v]
    else:
        v+=1
        count=0
        
for i in range(len(s)):
    print(''.join(s[i]))