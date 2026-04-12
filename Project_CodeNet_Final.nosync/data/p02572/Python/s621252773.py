n = int(input())
As = list(map(int, input().split()))
D = 10 ** 9 + 7
ans = 0
s = sum(As)

for a in As:
  ans += (s-a) * a
  
print(ans // 2 % D)