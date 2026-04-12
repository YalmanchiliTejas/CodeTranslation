n = int(input())
num_list = [ int(v) for v in input().split() ]
s = 0
for i in range(n):
  if max(num_list[:i+1]) <= num_list[i]:
    s += 1
print(s)