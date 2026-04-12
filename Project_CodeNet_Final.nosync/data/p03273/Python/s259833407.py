h,w=map(int,input().split())
a=list(list(i for i in input()) for j in range(h))
b=list(x for x in a if '#' in x)
c=zip(*list(y for y in zip(*b) if '#' in y ))
for d in c:
    print(''.join(d))
