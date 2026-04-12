N = int(input())
H = [int(i) for i in input().split(" ")]
Max = H[0]
count = 1
for i in range(1,N):
  if H[i]>=Max:
      count+=1
      Max=H[i]
print(count)