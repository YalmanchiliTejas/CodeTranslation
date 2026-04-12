n=int(raw_input())
a=map(int, raw_input().split())
ans=0
for i in range(n):
  if i == sum([a[j]<=a[i] for j in range(i)]): ans+=1
print ans

