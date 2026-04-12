'''
Created on 2020/08/29

@author: harurun
'''
def main():
  import itertools
  import sys
  pin=sys.stdin.readline
  pout=sys.stdout.write
  perr=sys.stderr.write
  
  N=int(pin())
  A=list(map(int,pin().split()))
  mod=10**9+7
  B=list(itertools.accumulate(A))
  ans=0
  for i in range(N-1):
    ans+=A[i]*(B[N-1]-B[i])
  print(ans%mod)
  return 
main()