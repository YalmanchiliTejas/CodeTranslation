a = int(input())
l = list(map(int, input().split()))
c = 1
for i in range(1, a):
  if l[i] >= max(l[:i]):
    c +=1
print(c)