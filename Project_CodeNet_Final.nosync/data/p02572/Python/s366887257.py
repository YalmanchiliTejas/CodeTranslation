n=int(input())
arr=list(map(int,input().split()))
count=0
pre=[arr[0]]
for i in range(1,len(arr)):
	pre.append((pre[-1]+arr[i]))
ans=0
for i in range(len(arr)-1,0,-1):
	ans+=(pre[i-1]*arr[i])
print(ans%((10**9)+(7)))