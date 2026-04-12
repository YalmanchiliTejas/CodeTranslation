n=int(input())
h=list(map(int,input().split()))

ans=0

for i in range(n):
  a = h[:i+1]
  if not h[i] < max(a):
    ans += 1
print(ans)