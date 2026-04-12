'''
Created on 2020/08/20

@author: harurun
'''
def main():
  import re
  import sys
  pin=sys.stdin.readline
  pout=sys.stdout.write
  perr=sys.stderr.write
  
  S=pin()[:-1]
  if re.fullmatch(r"[A-Z]*AC[A-Z]*",S)==None:
    print("No")
    return 
  print("Yes")
  return 

main()