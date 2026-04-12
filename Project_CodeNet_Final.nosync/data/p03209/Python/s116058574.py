from functools import lru_cache
@lru_cache(maxsize=None)
def b(n):
    if n<1:return 1
    return b(n-1)*2+3
@lru_cache(maxsize=None)
def p(n):
    if n<1:return 1
    return p(n-1)*2+1
def solve(n,x):
    if n<1:return int(x>0)
    if x-2<b(n-1):return(solve(n-1,x-1))
    return p(n-1)+solve(n-1,x-b(n-1)-2)+1
print(solve(*map(int,input().split())))