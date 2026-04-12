N = int(input())
values = [int(input()) for i in range(N)]
values = sorted(values)

sort_values = []
med = int(N/2) if N % 2 == 1 else int(N/2)-1
prev = values[med]
A = values[:med]
B = list(reversed(values[med+1:]))
BAsum = 0
for i in range(med+1):
  if i >= len(B):
    break
  now = B[i]
  BAsum += abs(now-prev)
  prev = now
  if i >= len(A):
    break
  now = A[i]
  BAsum += abs(now-prev)
  prev = now

med = int(N/2)
prev = values[med]
A = values[:med]
B = list(reversed(values[med+1:]))
ABsum = 0
for i in range(med+1):
  if i >= len(A):
    break
  now = A[i]
  ABsum += abs(now-prev)
  prev = now
  if i >= len(B):
    break
  now = B[i]
  ABsum += abs(now-prev)
  prev = now  

#print(A, B)
print(max([BAsum, ABsum]))