import collections
n=int(input())
X=[]
A=[51]*26
for i in range(n):
    s=input()
    X.append(s)
    Y=collections.Counter(s)
    for k,v in Y.items():
        if A[ord(k)-97]>v:
            A[ord(k)-97]=v
c=set(list(X[0]))
for i in range(1,n):
    c=c&set(list(X[i]))
c=list(c)
c.sort()

B=[ord(x)-97 for x in c]
ans=''
for i in B:
    ans+=A[i]*chr(i+97)
print(ans)