# -*- coding: utf-8 -*-
N = int(input())
A = list(map(int, input().split()))

answer = [max(A[0],A[1])]

list_sum = A[::2]
for i in range(1,len(list_sum)):
  list_sum[i] += list_sum[i-1]

for i in range(2,N):
  if i==2:
    answer.append(max(A[0],A[1],A[2]))
  elif i%2==0:
    answer.append(max(answer[-1], answer[-2]+A[i]))
  else:
    answer.append(max(answer[-2]+A[i], list_sum[(i-1)//2]))

print(answer[-1])