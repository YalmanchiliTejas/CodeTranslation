N = int(input())
As = []
for i in range(N):
  A = int(input())
  As.append(A)
def find2(s, A):
  import math
  a = 0
  b = len(s)
  while a < b:
    i = (a+b)//2
    if s[i] < A:
      b = i
    else:
      if a == i:
        break
      a = i
  return b

num = 1
c = As[0]
s = [c]
for i in range(1,N):
  A = As[i]
  index = find2(s, A)
  #index = -1
  #for j in range(len(s)):
  #  if s[j] < A:
  #    index = j
  #    break
  #print(s, A, index)
  if index < len(s):
    #print(i, A, "B", index)
    s[index] = A
  else:
    #print(i, A, "C")
    num += 1
    s.append(A)
    c = A
print(num)
