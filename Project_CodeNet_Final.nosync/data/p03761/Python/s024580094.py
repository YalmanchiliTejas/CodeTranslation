n=int(input())
s=[input() for _ in range(n)]
s=sorted(s,key=lambda x: len(x))
for i in range(n):
    s[i]=sorted(s[i])
x=''.join(set(s[0]))
x=sorted(x)
for i in range(len(x)):
    tmp=s[0].count(x[i])
    for j in range(1,n):
        tmp=min(tmp,s[j].count(x[i]))
    print(x[i]*tmp,end="")