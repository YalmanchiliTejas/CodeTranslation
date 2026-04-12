n = int(input())
h = list(map(int, input().split()))
count = 0
for i in range(n):
  if h[i] == max(h[:i+1]):
    count += 1
print(count)