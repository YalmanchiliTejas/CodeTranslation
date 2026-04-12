N = int(input())
H = list(map(int, input().split()))
count = 0
for i in range(N):
  l = sorted(H[:i + 1])
  if l[-1] <= H[i]:
    count += 1
print(count)