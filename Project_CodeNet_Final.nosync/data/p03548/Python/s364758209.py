#k = int(input())
#s = input()
#a, b = map(int, input().split())
#s, t = map(str, input().split())
#l = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]
#a = [list(input()) for _ in range(n)]
#a = [int(input()) for _ in range(n)]



x,y,z = map(int, input().split())

ans = x // (y+z)

if (x % (y+z) < z):
    ans -= 1
print(max(0,ans))
