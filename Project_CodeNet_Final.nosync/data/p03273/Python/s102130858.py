h,w=map(int, input().split())
a=[]
w=[False for _ in range(w)]
for _ in range(h):
    line=input()
    for i, ai in enumerate(line):
        if ai=='#':
            w[i]=True
    if '#' in line:
        a.append(line)

for ai in a:
    line=''
    for i, wi in enumerate(w):
        if wi:
            line+=ai[i]
    print(line)

