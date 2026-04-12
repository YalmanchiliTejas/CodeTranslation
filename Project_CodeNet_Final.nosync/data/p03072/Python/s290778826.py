n = int(input())
a = list(map(int,input().split()))
ret = 0
for i in range(n):
  if max(a[:i+1]) == a[i]: ret += 1
print(ret)