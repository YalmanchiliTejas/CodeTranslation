n=int(input())
cnt=[50]*26

for _ in range(n):
    s=input()
    curcnt=[0]*26

    for c in s:
        curcnt[ord(c)-ord('a')]+=1
    
    for i in range(26):
        cnt[i]=min(cnt[i],curcnt[i])
    
ans=''
for i in range(26):
    c=chr(i+ord('a'))
    while cnt[i]>0:
        ans=ans+c
        cnt[i]-=1
    

print(ans)