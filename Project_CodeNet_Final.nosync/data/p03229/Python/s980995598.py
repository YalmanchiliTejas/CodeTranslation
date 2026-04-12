N = int(input())
A = [int(input()) for i in range(N)]
A.sort()
l,l_1,l_2 = [],[],[]
if len(A) % 2 == 0:  
  for i in range(len(A)):
    if i <= len(A)/2 - 2:
      l.append(-2)
    elif i == len(A)/2 -1:
      l.append(-1)
    elif i == len(A)/2:
      l.append(1)
    else:
      l.append(2)
  ans_d = [A[i]*l[i] for i in range(len(A))]
  print(sum(ans_d))
if len(A) % 2 == 1:
  for i in range(len(A)):
    if i <= int(len(A)/2) -2:
      l_1.append(2)
      l_2.append(-2)
    elif int(len(A)/2) -1 <= i <= int(len(A)/2):
      l_1.append(1)
      l_2.append(-1)
    else:
      l_1.append(-2)
      l_2.append(2)
  l_1.sort()
  l_2.sort()
  ans_d1 = [A[i]*l_1[i] for i in range(len(A))]
  ans_d2 = [A[i]*l_2[i] for i in range(len(A))]
  print(max(sum(ans_d1),sum(ans_d2)))