n = int(input())
A = list(map(int, input().split()))
m = n//2
b, c = sorted(A)[m-1:m+1]
for i in A:
  if i < c:
    print(c)
  else:
    print(b)