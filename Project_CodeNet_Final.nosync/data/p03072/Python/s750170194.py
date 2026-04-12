#coding:utf-8
N=input()
H=map(int, raw_input().split())

ans=1
for i in range(1, N):
    ok=True
    for j in range(i):
        if H[j]>H[i]:ok=False
    if ok: ans+=1
print(ans)
