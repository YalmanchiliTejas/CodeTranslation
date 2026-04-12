n=int(input())
aList=[]
for i in range(n):
  aList.append(int(input()))

ans=0
if n%2==1:
  aList.sort()
  smallList1=aList[:(n+1)//2]
  bigList1=aList[(n+1)//2:]
  ans1=sum(bigList1)*2-sum(smallList1)*2+smallList1[-1]+smallList1[-2]

  smallList2=aList[:(n-1)//2]
  bigList2=aList[(n-1)//2:]
  ans2=sum(bigList2)*2-sum(smallList2)*2-bigList2[0]-bigList2[1]
  ans=max(ans1,ans2)
else:
  aList.sort()
  smallList=aList[:n//2]
  bigList=aList[n//2:]
  ans=sum(bigList)*2-sum(smallList)*2+smallList[-1]-bigList[0]
print(ans)