# coding: utf-8
# Your code here!
n=int(input())
h = list(map(int, input().split()))

ans=1

for i in range(1,len(h)):
  if len(list(filter(lambda x: x <= h[i], h[:i])))==i:
      ans=ans+1
print(ans)

