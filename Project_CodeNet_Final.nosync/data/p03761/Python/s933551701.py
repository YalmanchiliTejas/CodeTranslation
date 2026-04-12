n=int(input())
ans=list(input())
ans.sort()
for i in range(n-1):
    s=list(input())
    num1=0
    re=[]
    for j in range(len(ans)):
        if ans[j] in s:
            s.remove(ans[j])
        else:
            re.append(ans[j])
    for j in range(len(re)):
        ans.remove(re[j])
    if len(ans)==0:
        break
strans=""
for i in range(len(ans)):
    strans+=ans[i]
print(strans)
