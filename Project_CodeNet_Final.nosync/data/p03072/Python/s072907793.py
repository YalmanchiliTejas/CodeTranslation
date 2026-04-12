n = int(input())

h = list(map(int, input().split()))

result = 1
for i in range(1, n):
  if max(h[:i]) <= h[i]:
    result += 1

print(result)  