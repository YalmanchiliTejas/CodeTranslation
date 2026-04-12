n=int(input())
s=input()
k=int(input())
m=s[k-1]
news=''
for i in s:
    if i==m:
        news=news+m
    else:
        news=news+'*'
print(news)
    

