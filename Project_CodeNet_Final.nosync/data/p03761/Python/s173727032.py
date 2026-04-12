n=int(input())
s=[]
for i in range(n):
    s+=[input()]

a=[]
if len(s)==1:
    for i in s[0]:
        a+=[i]
    a.sort()
    a=''.join(a)
    print(a)

else:
    s1=s[0]
    s=s[1:]
    for i in s1:
        for j in range(len(s)):
            c1=0
            for k in range(len(s[j])):
                if i==s[j][k]:
                    s[j]=s[j][:k]+s[j][k+1:]
                    c1+=1
                    break
            if c1==0:
                break
        if c1==1:
            a+=[i]
    a.sort()
    a=''.join(a)
    print(a)


