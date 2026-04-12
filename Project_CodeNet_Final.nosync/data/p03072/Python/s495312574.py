n = int(input())
lis = list(map(int,input().split()))
ans = 0
nu = 0
for num in lis:
  if num >= nu:
    nu = num
    ans += 1
print(ans)