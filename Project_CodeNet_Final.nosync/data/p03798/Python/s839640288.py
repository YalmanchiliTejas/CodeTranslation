import sys
def I(): return int(sys.stdin.readline().rstrip())
def LS2(): return list(sys.stdin.readline().rstrip())  #空白なし

N = I()
s = LS2()
for i in range(N):
    if s[i] == 'o':
        s[i] = 0
    else:
        s[i] = 1

for a,b in [(0,0),(0,1),(1,0),(1,1)]:  # 1,2番目の動物で全探索
    A = [0]*N
    A[0] = a
    A[1] = b
    for i in range(2,N):
        A[i] = A[i-2] ^ A[i-1] ^ s[i-1]
    if A[0] == A[-2] ^ A[-1] ^ s[-1] and A[1] == A[-1] ^ A[0] ^ s[0]:
        A = ['S' if A[i] == 0 else 'W' for i in range(N)]
        print(''.join(A))
        exit()

print(-1)
