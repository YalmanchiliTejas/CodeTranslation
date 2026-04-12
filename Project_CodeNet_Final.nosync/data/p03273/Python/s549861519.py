h,w=map(int,input().split())
a=[list(input()) for i in range(h)]

l1=[]
for i in a:
    if '#' in i:
        l1.append(i)
l2=[]
for i in zip(*l1):
    if '#' in i:
        l2.append(i)
l3=zip(*l2)
for i in l3:
    print(''.join(i))