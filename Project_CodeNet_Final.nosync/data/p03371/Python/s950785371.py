
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
##############################

a, b, ab, x, y = map(int, input().split())

ans = float('inf')
for i in range(max(x, y)+1 ):
    price = i * 2 * ab + max(0, x-i)*a + max(0, y-i)*b
    ans = min(ans, price)

print(ans)
