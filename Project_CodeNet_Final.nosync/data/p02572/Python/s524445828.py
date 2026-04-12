n = int(input())
arr = list(map(int,input().split()))
su = sum(arr)
c = 0
for item in arr:
  c+= item*item
print(((su**2 - c)//2)%(10**9 + 7))
