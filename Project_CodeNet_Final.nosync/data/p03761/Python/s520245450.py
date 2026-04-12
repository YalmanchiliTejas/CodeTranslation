from collections import Counter
n=int(input())
sc=[]
for _ in range(n):
    s=input()
    sc.append(Counter(s))

ansc=sc[0]

for x in sc:
    ansc&=x

ans=sorted(ansc.elements())
for x in ans:
    print(x,end="")
