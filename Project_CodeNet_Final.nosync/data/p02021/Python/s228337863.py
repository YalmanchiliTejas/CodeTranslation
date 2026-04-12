n = int(input())
a = list(map(int, input().split()))

r = 100
for i in range(n):
  r = min(r, sum(a[:i+1])//(i+1))
print(r)


