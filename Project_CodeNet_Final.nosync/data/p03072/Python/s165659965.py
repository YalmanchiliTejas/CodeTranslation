n=int(input())
l=list(map(int,input().split()))
s=1
for i in range(1,n):
    if l[i]==max(l[:i+1]):
        s+=1
print(s)
