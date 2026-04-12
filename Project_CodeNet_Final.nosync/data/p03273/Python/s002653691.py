h,w=map(int,input().split())
a=[input() for _ in range(h)]
a=[i for i in a if "#" in i]
b=[("").join(list(i)) for i in list(zip(*a))]
b=[i for i in b if "#" in i]
c=[("").join(list(i))  for i in list(zip(*b))]
for i in c:
    print(i)