X,Y,Z = (int(i) for i in input().split())

ans = 0

while (ans+1) * (Y+Z) <= X-Z:
  ans += 1

print(ans)
