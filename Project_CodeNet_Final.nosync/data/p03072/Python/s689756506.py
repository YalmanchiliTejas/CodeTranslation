N = int(input())
H = list(map(int, input().split()))

cnt = 0
for i in range(2,N+1):
  if max(H[:i]) <= H[i-1]:
    cnt += 1
print(cnt+1)