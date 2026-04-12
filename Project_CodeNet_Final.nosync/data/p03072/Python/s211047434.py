N = int(input())

H = list(map(int, input().split()))

num_ryokan = 0
max_height = 0

for i in range(N):
  if max_height <= H[i]:#見えるとき
    num_ryokan +=1
    max_height = H[i]

print(num_ryokan)