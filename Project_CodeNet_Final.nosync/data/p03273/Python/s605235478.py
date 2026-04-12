def imp():return map(int,input().split())
h,w=imp()
l=[]
for _ in range(h):
    s=input()
    if '#' in s:l.append([x for x in s])

ans=[]
for j in range(w):
    s=""
    for i in range(len(l)):
        s+=l[i][j]
    if '#' in s: ans.append([x for x in s])

w=len(ans[0])
for j in range(w):
    s=""
    for x in ans:
        s+=x[j]
    print(s)





