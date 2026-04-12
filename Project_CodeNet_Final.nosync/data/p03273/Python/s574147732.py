h,w=map(int,input().split())
d=[list(input())  for i in range(h)]
for i in range(w)[::-1]:
    if not "#" in [d[j][i] for j in range(h)]:
        for j in range(h):del d[j][i]
for i in d:
    if "#" in i:print(*i,sep="")