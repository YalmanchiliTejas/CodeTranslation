import bisect

n=int(input())
arr=[int(input()) for _ in range(n)]
num=1
ans=[-arr[0]]
for i in range(1,n):
  if -arr[i]>=ans[-1]:
    ans.append(-arr[i])
  else:
    pos=bisect.bisect_right(ans,-arr[i])
    ans[pos]=-arr[i]
print(len(ans))