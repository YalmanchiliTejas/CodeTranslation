n=int(input())
l=list(map(int,input().split()))
nums=[x for x in range(n)]
cnt=0
for num in nums:
  s=l[:num+1]
  if(l[num]>=max(s)):
    cnt+=1
print(cnt)