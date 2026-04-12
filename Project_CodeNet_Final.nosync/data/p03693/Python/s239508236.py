#ABC064 A - RGB Cards
si = lambda: input()
ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))
r,g,b = map(str, input().split())
s = r+g+b
if int(s)%4==0:
    print('YES')
else:
    print('NO')

