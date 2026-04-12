N = int(input())
S = str(input())
K = int(input())

ans = ""

for c in S:
 if c == S[K-1]:
  ans += c;
 else:
  ans += "*"
print(ans)  
