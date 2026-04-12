n=int(input())
a=list(map(int,input().split()))
ans=[]
v=[]
ans=a[-1::-2]
if n%2==0:
    for i in range(0,n,2):
        v.append(a[i])
else:
    for i in range(1,n,2):
        v.append(a[i])
ans.extend(v)
moji=" ".join(map(str,ans))
print(moji)