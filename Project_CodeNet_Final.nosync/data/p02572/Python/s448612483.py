#k = int(input())
#s = input()
#a, b = map(int, input().split())
#s, t = map(str, input().split())
#l = list(map(int, input().split()))
#l = [list(map(int,input().split())) for i in range(n)]
#a = [input() for _ in range(n)]


N = int(input())
seq = list(map(int, input().split()))

s = 0
for i in range(N):
    s += seq[i]

s2 =0
for i in range(N):
    s2 += seq[i]**2


s0 = (s**2 -s2)//2

print(s0%(10**9+7))
