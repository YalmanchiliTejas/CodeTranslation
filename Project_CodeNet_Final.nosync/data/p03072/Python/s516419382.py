n = int(input())
L = list(map(int, input().split()))
cnt = 1
for i in range(1,n):
  if not L[i] < max(L[:i]):
    cnt += 1
print(cnt)