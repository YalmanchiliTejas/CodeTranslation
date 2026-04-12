def comb(n,k):
  if k==0:
    return 1
  if k==1:
    return n
  if k==2:
    return n*(n-1)//2
  if k==3:
    return n*(n-1)*(n-2)//6
  return None
def cnt(n,k):
  if k==0:
    return 1
  if k>len(n):
    return 0
  return (comb(len(n)-1,k)*9**k
          +(int(n[0])-1)*comb(len(n)-1,k-1)*9**(k-1)
          +cnt(n[1:].lstrip('0'),k-1))
def main():
  n=input()
  k=int(input())
  print(cnt(n,k))
main()