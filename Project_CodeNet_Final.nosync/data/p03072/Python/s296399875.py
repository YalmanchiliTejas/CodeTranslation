n = int(input())
x = list(map(int, input().split()))
temp = x[0]
ans = 1
for i in range(n - 1):
  if(x[i + 1] >= temp):
    ans += 1
    temp = x[i + 1]
print(ans)