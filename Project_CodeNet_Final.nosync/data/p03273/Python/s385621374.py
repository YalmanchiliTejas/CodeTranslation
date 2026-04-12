h,w=map(int,input().split())
l=[list(input()) for i in range(h)]
dl=[]
for i in range(h):
    if "#" not in l[i]:dl.append(i)
for i in dl[::-1]:
    del l[i]
l = [list(x) for x in zip(*l)]
dl=[]
for i in range(w):
    if "#" not in l[i]:dl.append(i)
for i in dl[::-1]:
    del l[i]
l = [list(x) for x in zip(*l)]
for i in l:print("".join(map(str,i)))