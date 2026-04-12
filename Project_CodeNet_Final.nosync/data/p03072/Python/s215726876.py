n = int(input())
a = list(map(int,input().split()))

k = -1
ans = 0
for i in a :
  if (k <= i):
    ans += 1
    k = i
         
print(ans)
