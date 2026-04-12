import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())


A,B,C,X,Y = MI()

ans = 10**18
for i in range(0,2*max(X,Y)+1,2):  # i:ABピザを買う枚数
    ans = min(ans,A*max(0,X-i//2)+B*max(0,Y-i//2)+C*i)

print(ans)
