MOD=10**9+7
N=int(input())
alist=list(map(int,input().split()))

slist=[0]*N
sum_a=0
for i in reversed(range(N)):
  sum_a+=alist[i]
  slist[i]=sum_a  
#print(slist)

answer=0
for i in range(N-1):
  answer+=alist[i]*slist[i+1]
  answer%=MOD
  
print(answer)