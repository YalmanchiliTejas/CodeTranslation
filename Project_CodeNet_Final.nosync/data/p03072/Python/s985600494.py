N = int(input())
A = list(map(int, input().split()))
B = [A[0]]
for i in range(N-1):
  B += [max(B[-1], A[i+1])]

ans = 0
for i in range(N):
  if A[i] == B[i]:
    ans += 1
    
print(ans)