h,w=map(int,input().split())
s=[input() for _ in range(h)]
a=[x for x in s if '#' in x]
b=[x for x in zip(*a) if '#' in x]

for i in zip(*b):
    print("".join(i))