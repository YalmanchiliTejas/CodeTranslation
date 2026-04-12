n = int(input())
a = list(map(int,input().split()))
ans = 0
mx = 0
for i in range(n):
  if mx<=a[i]:
    ans+=1
    mx = a[i]
print(ans)