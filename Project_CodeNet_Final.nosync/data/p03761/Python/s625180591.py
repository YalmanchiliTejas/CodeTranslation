from collections import Counter,defaultdict
n=int(input())
s=[input() for i in range(n)]

dict=defaultdict(lambda:60) #|S|<=50
sum_set=set(s[0])

for i in range(n):
    cnter=Counter(s[i])
    chset=set(s[i])
    for item in chset:
        dict[item]=min(dict[item],cnter[item])

    sum_set=sum_set & chset

ans=[]
for item in sum_set:
    for i in range(dict[item]):
        ans.append(item)

ans.sort()
print(*ans,sep="")