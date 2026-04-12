printn = lambda x: print(x,end='')
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
ins = lambda : input().strip()
DBG = True # and False
BIG = 10**18
R = 10**9 + 7

def ddprint(x):
  if DBG:
    print(x)

s = ins()
hasa = (s[0]=='A') or (s[1]=='A') or (s[2]=='A')
hasb = (s[0]=='B') or (s[1]=='B') or (s[2]=='B')
if hasa and hasb:
    print('Yes')
else:
    print('No')
