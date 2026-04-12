N = int(input())
lis=[]
for i in range(N):
  lis.append(int(input()))
lis.sort()

m = (N-1)//2
if N%2==1:
  ans1 = sum(lis[0:m+1])*(-2)+sum(lis[m+1:])*2+lis[m]+lis[m-1]
  ans2 = sum(lis[0:m])*(-2)+sum(lis[m:])*2-lis[m]-lis[m+1]
  ans = max(ans1,ans2)
else:
  ans = sum(lis[0:m+1])*(-2)+sum(lis[m+1:])*2+lis[m]-lis[m+1]
print(ans)