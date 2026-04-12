N = int(input())
A = list(map(int,input().split()))
ans = 0
now = A[0]
for i in A:
  if now <= i:
    ans += 1
    now = i
print(ans)