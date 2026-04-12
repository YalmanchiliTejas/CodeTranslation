def ns():
    import sys
    return map(int, sys.stdin.readline().split())
  
def ss():
    import sys
    return list(sys.stdin.readline().strip())
  
N, = ns()
S = ss()
K, = ns()

c = S[K-1]
print(''.join(s if s == c else '*' for s in S))
