#r, d, x = map(int,input().split())
n = int(input())
h = list(map(int,input().split()))
#s = input()

ans = 0
for i in range(len(h)):
  if h[i] == max(h[:i+1]):
    ans += 1
print(ans)