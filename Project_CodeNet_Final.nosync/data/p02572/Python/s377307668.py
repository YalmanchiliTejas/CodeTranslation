n = int(input())
a = list(map(int,input().split()))

s = sum(a)
t = sum(map(lambda x:x**2,a))
ans = ((s**2 - t)//2) % (10**9 + 7)
print(ans)