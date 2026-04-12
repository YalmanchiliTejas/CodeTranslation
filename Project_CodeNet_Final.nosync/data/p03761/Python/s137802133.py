n = int(input())
s = [input() for i in range(n)]
ans_list = [100000] * 26
ans = ""
ord_a = ord("a")
for i in s:
  mini_ans = [0] * 26
  for j in i:
    mini_ans[ord(j) - ord_a] += 1
  o = 0
  for ans1,now in zip(ans_list,mini_ans):
    ans_list[o] = min(ans1,now)
    o += 1
for i,j in enumerate(ans_list):
  ans += chr(ord_a + i) * j
print(ans)
  