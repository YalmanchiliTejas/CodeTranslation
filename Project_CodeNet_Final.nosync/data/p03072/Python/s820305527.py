n=int(input())
h=input().split()
ans=0
hi=0
for i in range(n):
  if int(h[i])>=hi:
    ans += 1
    hi = int(h[i])
print(ans)