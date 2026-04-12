n=int(input())
a=[chr(i)for i in range(97,97+26)]
s=[input()for i in range(n)]
l=[]
for i in a:
 c=50
 for j in s:c=min(c,j.count(i))
 l.append(i*c)
print("".join(l))