n=int(input())
a=input().split()
for i in range(n):
  a[i]=int(a[i])
answer=1
highest=a[0]
for i in range(1,n):
  if a[i]>=highest:
    answer=answer+1
    highest=a[i]
print(answer)