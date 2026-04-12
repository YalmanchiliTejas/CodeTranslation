from collections import Counter
n = int(input())
data = [k for k in input()]

ans = Counter(data)
for i in range(n-1):
  tmp = Counter([k for k in input()])
  for j in set(data):
    ans[j] = min(ans[j], tmp[j])
#    print(j, ans[j], tmp[j], min(ans[j], tmp[j]))
ans_list = list(set(list(ans.elements())))
ans_list.sort()
answer = ""
for i in ans_list:
  answer += i*ans[i]
print(answer)
