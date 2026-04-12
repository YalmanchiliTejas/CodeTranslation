#k = int(input())
#s = input()
#a, b = map(int, input().split())
#s, t = map(str, input().split())
#l = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]

n = int(input())
h = list(map(int, input().split()))

ans = 0
vi = h[0]

for i in range(n):
    if h[i] >= vi:
        ans += 1
        vi = h[i]
print(ans)

