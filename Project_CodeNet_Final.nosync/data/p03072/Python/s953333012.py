n = int(input())
H = [0] + list(map(int, input().split()))
counter = 0
for i in range(1, n+1):
  if H[i] >= max(H[:i]):
    counter += 1
print(counter)