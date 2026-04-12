N = int(input())
A = [int(input()) for _ in range(N)][::-1]
def LIS(L):
  from bisect import bisect
  seq=[]
  for i in L:
    pos=bisect(seq,i)
    if len(seq)<=pos:
      seq.append(i)
    else:
      seq[pos]=i
  return len(seq)
print(LIS(A))
