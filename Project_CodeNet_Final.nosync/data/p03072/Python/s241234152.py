from sys import stdin

n = int(stdin.readline().rstrip())
hotel = list(map(int, input().split()))

max = 0
count = 0
for i in range(n):
  if (max <= hotel[i]):
    max = hotel[i]
    count +=1

print("{0}".format(count))
