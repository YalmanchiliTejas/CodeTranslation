n=int(input())
dlist=[]
for _ in range(n):
    s = input()
    dict={}
    for char in s:
        if char not in dict:
            dict[char]=1
        else:
            dict[char]+=1
    dlist.append(dict)
first=dlist[0]
for i in range(1,n):
    for key in first:
        if key not in dlist[i]:
            first[key]=0
        else:
            first[key]=min(first[key],dlist[i][key])
first=sorted(first.items(),key=lambda x: x[0])
ans=""
for (key,value) in first:
    ans+=key*value
print(ans)