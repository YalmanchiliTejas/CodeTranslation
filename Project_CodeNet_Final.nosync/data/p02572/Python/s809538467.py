a=int(input())
m_list=list(map(int,input().split()))
sum=sum(m_list)
count=0
for i in range(a) :
  count+=m_list[i]**2

answer=(sum**2-count)//2
print(answer%(10**9+7))