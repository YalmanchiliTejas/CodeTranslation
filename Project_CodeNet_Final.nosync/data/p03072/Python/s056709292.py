N = int(input())
H = input().split()
H = [int(x) for x in H]
border = 0
answer = 0
for i in range(N):
  if H[i] >= border:
    border = H[i]
    answer = answer + 1

print(answer)