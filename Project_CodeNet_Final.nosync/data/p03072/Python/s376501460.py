n = int(input())
h = list(map(int, input().split()))
cnt = 0
for i in range(len(h)):
  low = [num for num in h[0:i] if num > h[i]]
  if len(low) == 0:
    cnt += 1
print(cnt)