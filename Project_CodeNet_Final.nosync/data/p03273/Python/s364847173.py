h,w=map(int,input().split())
a=[]
for _ in range(h):
    ai = input()
    if '#' in ai:
        a.append(ai)
ans=['']*len(a)
for i in range(w):
    if sum([a[j][i]=='#' for j in range(len(a))])==0:
        continue
    for j in range(len(a)):
        ans[j]+=a[j][i]
for ansi in ans:
    print(ansi)
