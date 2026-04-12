n = int(input())
h = list(map(int, input().split()))

c = 0
for i in range(len(h)):
  if max(h[:i+1]) == h[i]:
    c += 1
print(c)