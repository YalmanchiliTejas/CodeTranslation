import itertools
import math

def solve():
  N = int(input())
  K = int(input())
  log_N = math.ceil(math.log10(N+1))
  digit_table = range(0,log_N)
  ret = 0
  for comb in itertools.combinations(digit_table, K):
    num = 0
    stack = [0]
    next_stack = []
    log_N
    if sum(9*(10**c) for c in comb) <= N: 
      ret += 9**K
      continue
    for c in comb:
      while stack:
        num_base = stack.pop()
        for d in range(1,10):
          num = num_base+d*10**c

          # print(num)
          if c == comb[-1]:
            if num <= N: 
              # print(num)
              ret += 1
          else:
            next_stack.append(num)

      stack = next_stack
      next_stack = []

  print(ret)
  
solve()