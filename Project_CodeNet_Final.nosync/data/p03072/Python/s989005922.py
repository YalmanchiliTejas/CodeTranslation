c=int(input())
n=list(map(int, input().split()))

ans = 0
max = n[0]
for i in n:
  if max <= i:
    ans += 1
    max = i
print(ans)