n=int(input())
s=[]
for i in range(n):
    if i==0:
        x=input()
        s.append(x)
        letter=set(x)
    else:
        x=input()
        s.append(x)
        letter=set(x) & letter
letter=sorted(letter)
count={}
for j in letter:
    for k in s:
        if not j in count:
            count[j]=k.count(j)
        else:
            if count[j]>k.count(j):
                count[j]=k.count(j)
ans=""
for x in letter:
    ans=ans+x*count[x]
print(ans)

    