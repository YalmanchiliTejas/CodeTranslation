n = int(input())
h = list(map(int,input().split()))
ma = h[0]
ans = 0
for i in h:
  if i>=ma:
    ma = i
    ans +=1
print(ans)