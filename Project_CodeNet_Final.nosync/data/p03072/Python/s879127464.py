n = int(input())
#mont = [int(input()) for i in range(n)]
mont = list(map(int,input().split()))
count = 0
for i in range(n):
  if mont[i] >= max(mont[:i+1]):
    count += 1
print(count)