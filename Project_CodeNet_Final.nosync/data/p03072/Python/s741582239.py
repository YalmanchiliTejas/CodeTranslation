N = int(input())
H = list(map(int,input().split()))
count = 0
ma = H[0]
for i in range(N):
  if H[i]>=ma:
    ma = H[i]
    count+=1
print(count)