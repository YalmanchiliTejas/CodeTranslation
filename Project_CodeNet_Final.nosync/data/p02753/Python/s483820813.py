import sys
sys.setrecursionlimit(10 ** 7)
read = sys.stdin.buffer.read 
inp = sys.stdin.buffer.readline
def inpS(): return inp().rstrip().decode()
readlines = sys.stdin.buffer.readlines 
MOD = 10**9+7

S = inpS()
ans = "No"
if S.count("A")!=3:
  if S.count("B")!=3:
    ans = "Yes"
print(ans)