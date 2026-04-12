'''
Created on 2020/08/20

@author: harurun
'''
def main():
  import sys
  pin=sys.stdin.readline
  pout=sys.stdout.write
  perr=sys.stderr.write
  
  N=int(pin())
  S=pin()[:-1]
  K=int(pin())
  t=S[K-1]
  for i in range(N):
    if t==S[i]:
      pout(t)
    else:
      pout("*")
  print()
  return 
main()