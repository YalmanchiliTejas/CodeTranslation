a = int(input())
h = [int(i) for i in input().split()]
count = 0
for x in range(a):
 if h[x] >= max(h[:x+1]):
  count +=1
print(count)