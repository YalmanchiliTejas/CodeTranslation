#k = int(input())
#s = input()
#a, b = map(int, input().split())
#s, t = map(str, input().split())
#l = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]
#a = [list(input()) for _ in range(n)]



r,g,b = map(int, input().split())

if (r*100+g*10+b)%4 == 0:
    print("YES")
else:
    print("NO")
