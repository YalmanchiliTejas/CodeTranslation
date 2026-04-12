n=input()
h=map(int,input().split())
ans=0
g=0
for i in h:
    if g<=i:
        ans+=1
        g=i
        continue
    
print(ans)