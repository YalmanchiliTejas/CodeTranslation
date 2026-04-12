import collections as col
n = int(input())
li = [col.Counter(list(input())) for _ in range(n)]

ans = ""
#c = col.Counter(li)
for i in range(26):
  tmp = 100
  for j in range(n):
    tmp = min(tmp,li[j][chr(ord("a")+i)])
  ans += chr(ord("a")+i)*tmp
  #print(li[0][chr(ord("a")+i)])
#print(li)
print(ans)