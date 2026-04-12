N = int(input())
l = list(map(int, input().split()))
counter=0
for i in range(N):
  if max(l[:i+1])==l[i]:
   counter += 1
print(counter)