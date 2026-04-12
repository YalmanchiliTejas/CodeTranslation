from string import ascii_lowercase
alp=ascii_lowercase
ans=[float("inf")]*26
n=int(input())
for i in range(n):
    cnt=[0]*26
    s=input()
    for j in s:
        p=alp.index(j)
        cnt[p]+=1
    for j in range(26):
        ans[j]=min(ans[j],cnt[j])
output=[]
for i in range(26):
    for j in range(ans[i]):
        output.append(alp[i])
print("".join(output))