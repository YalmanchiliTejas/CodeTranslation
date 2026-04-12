N = int(input())
H_hight = list(map(int, input().split()))
count = 1

for i in range(N):
  if max(H_hight[0:i+1]) == H_hight[i]:
    count += 1
    if i==0:
      continue

print(count-1)
  