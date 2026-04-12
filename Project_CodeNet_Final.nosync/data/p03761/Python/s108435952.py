n=int(input())
a=[list(map(str,input().split())) for i in range(n)]
# print(a)
# print(len(a[0][0]))
ans=[]
cnt=0
# s=a[1][0]
# s=s.replace("a","b",1)
# print(s)

# print(a[0][0][0])
# print(a[0][0])
for i in range(len(a[0][0])):
    cnt=0
    for k in range(1,n):
        if (a[0][0][i] in a[k][0]):
            a[k][0]=a[k][0].replace(a[0][0][i],'',1)
            # print(a[k][0])
            cnt+=1
            # print(a)
    if cnt==n-1:
        ans.append(a[0][0][i])
ans.sort()
res=''
for x in ans:
    res+=x
print(res)