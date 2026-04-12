h,w=map(int,input().split())
s=[]
for _ in range(h):
    a = input() 
    if "#" in a:
        s.append(a)
d = []
for i in zip(*s):
    if "#" in i:
        d.append(i)
for j in zip(*d):
    print(*j,sep="")