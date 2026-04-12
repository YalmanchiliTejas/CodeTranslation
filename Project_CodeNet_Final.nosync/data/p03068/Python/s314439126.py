n = int(input())
s = input()
k = int(input())

ans = [a  if a == s[k-1] else "*" for a in s]
print("".join(ans))