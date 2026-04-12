N = int(input())
S = input()
K = int(input())

compare_str = S[K - 1]
result_str = ''
for s in list(S):
  if compare_str == s:
    result_str += s
  else:
    result_str += '*'
print(result_str)