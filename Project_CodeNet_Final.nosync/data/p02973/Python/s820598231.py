import bisect
n=int(input())
al=[-int(input()) for _ in range(n)]
ans=[al[0]]
for a in al[1:]:
    i=bisect.bisect(ans,a)
    if i==len(ans):
        ans.append(a)
    else:
        ans[i]=a
print(len(ans))