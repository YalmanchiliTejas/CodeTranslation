input()
H = list(map(int, input().split()))

count = 1
for i in range(len(H)-1):
  count += 1 if max(H[:i+1])<=H[i+1] else 0
print(count)