from bisect import bisect_left, bisect_right

N = int(input())

color = []
color.append(int(input()))

for i in range(N-1):
  A = int(input())
  
  if color[-1] >= A:
    color.append(A)

  else:
    color.reverse()
    l = bisect_left(color,A)
    color[l-1] = A
    color.reverse()


print(len(color))