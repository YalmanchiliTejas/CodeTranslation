# n=int(input())
x, y, z = map(int, input().split())
# l=list(map(int,input().split()))
#l=[list(map(int,input().split())) for i in range(n)]
ans = x // (y + z)
if x - ans*(y + z) < z:
    ans = max(0, ans-1)
print(ans)