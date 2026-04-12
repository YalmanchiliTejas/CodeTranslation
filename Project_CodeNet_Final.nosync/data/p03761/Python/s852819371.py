import collections
n=int(input())
a=collections.Counter(input())
for i in range(n-1):
    s=collections.Counter(input())
    a=a&s
ans=""
k=a.keys()
v=a.values()
for i,j in zip(k,v):
    ans+=i*j
print("".join(sorted(ans)))
    