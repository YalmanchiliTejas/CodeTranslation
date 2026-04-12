N = int(input())
H = list(map(int, input().split()))

answer=1
for i in range(1,N):
  if max(H[:i]) <= H[i]:
    answer +=1
    
print(answer)