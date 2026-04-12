N=int(input())
a=0
ans=0
for i in list(map(int, input().split())):
    if a<=i:
        ans+=1
        a=i
print(ans)