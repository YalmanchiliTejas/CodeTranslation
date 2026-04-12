count = 0
n = int(input())
h = list(map(int, input().split()))
ma = h[0]

for i in h:
  if i >= ma:
    count += 1
    ma = i 

print(count)