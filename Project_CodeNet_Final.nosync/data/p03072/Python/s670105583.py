N = int(raw_input())
A=map(int, raw_input().split(' '))

shr = A[0]
c = 1

for i in range(1, N):
      if A[i] >= shr:
              c += 1
              shr = A[i]

print(c)
