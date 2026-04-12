N = int(input())
l = [int(x) for x in input().split()]
count = 0
for i in range(N):
  if max(l[:i+1]) == l[i]:
    count += 1
print(count)