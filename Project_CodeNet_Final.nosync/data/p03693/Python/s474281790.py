import sys
input = sys.stdin.readline

r, g, b = map(int, input().split())
if int(str(r)+str(g)+str(b))%4 == 0:
    ans = 'YES'
else:
    ans = 'NO'
print(ans)