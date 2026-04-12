N = int(input())
H = list(map(int, input().split()))

low = H[0]
count = 1

for i in range(1,N):
  if H[i] >= low:
    count += 1
    low = H[i]
    
print(count)
  