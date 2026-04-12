#周期m以下

n,x,m=map(int, input().split())

used = [0]*(m+1)
used_list=[]
pre=x

flag0=False
s=-1;t=-1
for i in range(m+1):
    if pre==0:
        flag0=True
        break
    now=(pre*pre)%m
    if used[pre]:
        s=used[pre]
        break
    used[pre]=i
    used_list.append(pre)
    pre=now
    
l=len(used_list[s:])
try:
    ans=sum(used_list[:s])+sum(used_list[s:])*((n-s)//l)+sum(used_list[s:s+(n-s)%l])
    if not flag0:
        print(ans)
    else:
        print(sum(used_list))
except:
    print(sum(used_list))