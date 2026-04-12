N = int(input())
H = list(map(int, input().split()))

ma = 0
Ans = 0
for i in H:
  if i >= ma:
    ma = i
    Ans += 1

print(Ans)
