n=int(input())
s=[input() for i in range(n)]
c=[[0]*26 for i in range(n)]
a=[0]*26

for i,ss in enumerate(s):
    for sss in ss:
        c[i][ord(sss)-97]+=1

for i in range(26):
    tmp=10**9
    for j in range(n):
        tmp=min(tmp,c[j][i])
    a[i]=tmp

ans=[]
for i,aa in enumerate(a):
    t_str=chr(i+97)
    ans+=[t_str]*aa
ans.sort()
print(''.join(ans))
