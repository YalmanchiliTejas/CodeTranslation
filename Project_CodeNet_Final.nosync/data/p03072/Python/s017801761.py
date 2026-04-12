n=int(input())
h=list(map(int,input().split()))
a=[]
for i in range(n):
    a.append(h[-(i+1)])
#print(a)
s=0
#print(max(a[2:]))
for i in range(n):
    if a[i]>=max(a[i:]):
        s+=1
print(s)