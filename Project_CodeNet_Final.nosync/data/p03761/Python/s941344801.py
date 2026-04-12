from collections import Counter
import string
MAX_N = 50

n = int(input())
cc = [Counter(input()) for _ in range(n)]

ans = ''
for c in string.ascii_lowercase:
  min_num = MAX_N
  for counter in cc:
    min_num = min(min_num,counter[c]) 
  ans += c*min_num
  
print(ans)  