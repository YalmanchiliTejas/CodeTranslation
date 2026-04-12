h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
for i in range(h):
    if '#' not in a[i]:
        a[i]=['n']*w
for i in range(w):
    l=[a[j][i] for j in range(len(a))]
    if '#' not in l:
        for k in range(len(a)):
           a[k][i]='n'
for i in a:
    l=[x for x in i if x!='n']
    if l:
        print(''.join(l))