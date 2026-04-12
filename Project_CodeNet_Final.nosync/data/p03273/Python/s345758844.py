h,w=map(int,input().split())
tmp=[]
jg=[0 for _ in range(0,w)]
s=""
for i in range(0, h):
    s = input()
    if s != '.'*w:
        tmp.append(s)
    for j in range(0,len(s)):
        if s[j] == '#':
            jg[j] = 1
rs=[]
for i in range(0, len(tmp)):
    s=list(tmp[i])
    for k in range(0,w):
        if jg[k] == 0:
            s[k] = ''
    rs.append(s)
for _ in rs:
    print(''.join(_))