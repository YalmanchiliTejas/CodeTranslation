n = int(input()) - 1
s = list(map(int, input().split()))
ans = 0
for i in range(1,(n+1)//2):
  tmp = 0
  if (n % i):
    for a,b in zip(s[n-i:i:-i],s[i::i]):
      tmp += a+b
      ans = max(ans,tmp)
  else:
    for k,(a,b) in enumerate(zip(s[n-i::-i],s[i::i]),1):
      if n <= 2*k*i:
        break
      tmp += a+b
      ans = max(ans,tmp)
print(ans)
