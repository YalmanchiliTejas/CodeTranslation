n=int(input())
al=[chr(ord('a')+i) for i in range(26)]
ansd={x:100 for x in al}
for i in range(n):
    d={x:0 for x in al}
    s=input()
    for a in s:
        d[a]+=1
    for x in al:
        ansd[x]=min(ansd[x],d[x])
a=''
for x in al:
    num=ansd[x]
    for i in range(num):
        a+=x
print(a)