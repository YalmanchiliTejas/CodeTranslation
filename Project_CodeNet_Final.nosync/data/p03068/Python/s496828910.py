import re
n,s,k=[input()for _ in "nsk"]
print(re.sub(f"[^{s[int(k)-1]}]","*",s))