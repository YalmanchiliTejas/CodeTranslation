N = int(input())
H = [int(x) for x in input().split()]
max_h = H[0]
answer = 1
for i in range(1, len(H)):
  if H[i]>=max_h:
    answer+=1
    max_h = H[i]
print(answer)