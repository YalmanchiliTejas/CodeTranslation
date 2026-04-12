ri = lambda S: [int(v) for v in S.split()]
def rii(): return ri(input())
 
N, M = rii()

print("Yes" if N == M else "No")