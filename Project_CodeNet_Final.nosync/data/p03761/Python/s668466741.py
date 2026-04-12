al = [chr(ord('a') + i) for i in range(26)]

cnt = {}
for i in al:
  cnt[i] = []

for i in range(int(input())):
  k = input()
  for j in al:
    cnt[j].append(k.count(j))

ret = ""
for i in al:
  ret += i * min(cnt[i])
print(ret)