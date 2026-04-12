n = int(input())
s = input()
k = int(input())

ans = ['*'] * len(s)
replace = s[k-1]

for i in range(len(s)):
  if s[i] == replace:
    ans[i] = replace
print("".join(ans))