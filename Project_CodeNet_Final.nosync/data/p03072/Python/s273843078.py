import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))  #空白あり

N = I()
H = LI()
ans = 0
r = 0
for i in range(N):
    if H[i] >= r:
        ans += 1
        r = H[i]
print(ans)
