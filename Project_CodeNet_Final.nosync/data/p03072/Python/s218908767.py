n = int(input())
list = list(map(int,input().split()))
max = list[0]
count = 0
for i in range(n):
  if list[i] >= max:
    count += 1
    max = list[i]
print(count)