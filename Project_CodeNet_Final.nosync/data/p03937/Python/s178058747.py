h,w=map(int,input().split())
a=[input() for _ in range(h)]
t=0
for i in range(h):
    t+=a[i].count('#')
if t==h+w-1:
    print('Possible')
else:
    print('Impossible')