n = int(input())
s = [list(input()) for i in range(n)]
ans = sorted(list(set(s[0])))
numbers = [100 for i in range(len(ans))]
for i in range(n):
  for j in range(len(ans)):
    numbers[j] = min(numbers[j], s[i].count(ans[j]))
ret = ""
for i in range(len(ans)):
  ret += ans[i]*numbers[i]
print(ret)