import itertools

n=int(input())
a_list=list(map(int,input().split()))
sum=0
ps = list(itertools.accumulate(a_list))
for i in range(n-1):
  sum+=a_list[i]*(ps[n-1]-ps[i])

s=sum%(10**9+7)
print(s)
