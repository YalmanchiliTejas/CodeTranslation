n=int(input())
s=str(input())
k=int(input())
a=s[k-1]
#print(a,s)
for i in range(n):
    if s[i]!=a:
        s=s[:i]+'*'+s[i+1:]
print(s)
