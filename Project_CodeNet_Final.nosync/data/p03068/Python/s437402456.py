n = int(input())
s = input()
sl = list(s)
k = int(input())
for i in range(n):
  if sl[i] != sl[k-1]:
    sl[i] = "*"
ans = ""
for x in sl:
  ans += x
print(ans)